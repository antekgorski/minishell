## Brief Summary

![minishell](https://github.com/servettonga/minishell_project/assets/83537967/da9e9cf6-87ff-4ea0-a71a-80c2c6b7ed61)


1. Initialize shell
	1. Set up signal handlers for `SIGINT`, `SIGQUIT`, `EOF`
	2. Initialize command history

2. Main shell loop
	1. Display prompt
	2. Read command using [`readline()`](./Function%20Descriptions.md#readline)
	3. Add command to history using [`add_history()`](./Function%20Descriptions.md#add_history)
	4. [Parse command](#parse-command)
		- Handle quotes and special characters.
		- Handle environment variables and special variables like `$?`.
		- Split command into pipeline stages.
		- For each stage, split into command and arguments.
	5. [Execute command](#execute-command)
		1. If command is a builtin, execute it directly.
		2. Otherwise, fork a new process.
			- Set up redirections and pipes using [`dup2()`](./Function%20Descriptions.md#dup-dup2).
			- Execute command using [`execve()`](./Function%20Descriptions.md#execve).
			- If [`execve()`](./Function%20Descriptions.md#execve) returns, print error message and exit.
		3. If command is a pipeline, repeat forking a new process for each stage.
		4. Wait for all processes in the pipeline to finish using [`waitpid()`](<./Function%20Descriptions.md#wait-waitpid>).
	6. Repeat from _Display prompt_

3. [Builtin commands](#builtin-commands)
	- `echo`: print arguments, handle `-n` option.
	- `cd`: change directory using [`chdir()`](./Function%20Descriptions.md#chdir).
	- `pwd`: print current directory using [`getcwd()`](./Function%20Descriptions.md#getcwd).
	- `export`: add environment variable.
	- `unset`: remove environment variable.
	- `env`: print environment variables.
	- `exit`: exit shell.

4. [Signal handlers](#signal-handlers)

	`ctrl-C`, `ctrl-D` and `ctrl-\` should behave like in bash

	In interactive mode:
	- `SIGINT`: displays a new prompt on a new line.
	- `EOF`: exits the shell.
	- `SIGQUIT`: do nothing.

--------------------

### Parse Command
1. Start with the full command string
2. Handle quotes
	- If a single quote is encountered, read until the next single quote, treating the contents as a **single argument**.
	- If a double quote is encountered, read until the next double quote, treating the contents as a single argument but expanding any variables prefixed with `$`.
3. Handle special characters
	- If a special character like `>`, `<`, `|`, or `&` is encountered outside of quotes, treat it as a separate argument.
4. Handle environment variables and special variables
	- If a `$` is encountered outside of single quotes, read until the next non-alphanumeric character and replace the `$` and following characters with the value of the corresponding environment variable or special variable.
5. Split command into pipeline stages
	- If a `|` is encountered outside of quotes, split the command into separate stages at each `|`.
6. For each stage, split into command and arguments
	- Split the stage into words at each space, treating each word as a **separate argument**.
	- The first word is the command to be executed, and the remaining words are its arguments.

--------------------

### Execute Command
1. Check if the command is a builtin
	- If it is, execute it directly in the shell process.
	- If it's not, proceed to the next step.
2. Fork a new process
	- The shell process creates a duplicate of itself using the [`fork()`](./Function%20Descriptions.md#fork) system call.
	- The new process (child) will execute the command, while the original process (parent) will wait for the child to finish.
3. Set up redirections and pipes
	- If the command includes redirection operators (`>`, `<`), change the file descriptors of the child process using [`dup2()`](./Function%20Descriptions.md#dup-dup2) before executing the command.
	- If the command is part of a pipeline, set up a pipe between this process and the next one in the pipeline.

	> < should redirect input.
	>
	> \> should redirect output.
	>
	> << should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
	>
	> \>> should redirect output in append mode.

	See: [Here Strings](https://bash.cyberciti.biz/guide/Here_strings), [Here Documents](https://bash.cyberciti.biz/guide/Here_documents)

4. Execute the command
	- The child process replaces its own image with the command using the [`execve()`](./Function%20Descriptions.md#execve) system call.
	- If [`execve()`](./Function%20Descriptions.md#execve) returns, it means there was an error (like the command not being found), so print an error message and exit.
5. If the command is a pipeline, repeat steps _Fork_ to _Execute_ for each stage in the pipeline
6. Wait for all processes in the pipeline to finish
	- The parent process uses the [`waitpid()`](<./Function%20Descriptions.md#wait-waitpid>) system call to wait for each child process to finish.
	- If a child process is stopped or terminated, [`waitpid()`](<./Function%20Descriptions.md#wait-waitpid>) returns and the parent can continue.

--------------------

### Builtin Commands

1. `echo`: Prints its arguments. If the `-n` option is provided, it does not output the trailing newline.
2. `cd`: Changes the current directory of the shell to the directory provided as argument. Uses the [`chdir()`](./Function%20Descriptions.md#chdir) system call.
3. `pwd`: Prints the current working directory of the shell. Uses the [`getcwd()`](./Function%20Descriptions.md#getcwd) system call.
4. `export`: Adds an environment variable.
5. `unset`: Removes an environment variable.
6. `env`: Prints all environment variables. See: [Common Environment Variables](https://www.digitalocean.com/community/tutorials/how-to-read-and-set-environmental-and-shell-variables-on-linux#common-environmental-and-shell-variables)
7. `exit`: Exits the shell.

--------------------

### Signal Handlers

1. `SIGINT`: In interactive mode, when the user types `Ctrl+C`, the shell displays a new prompt on a new line.
2. `EOF`: When the user presses `Ctrl+D`, the shell exits.
3. `SIGQUIT`: When the user presses `Ctrl+\`, the shell does nothing in interactive mode.

--------------------
