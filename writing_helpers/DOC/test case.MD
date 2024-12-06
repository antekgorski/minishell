# Test Cases
## 1. General Behavior and Parsing
### Simple Command
- Execute a simple command with an absolute path like `/bin/ls` without any options.
- Empty command.
- Only spaces or tabs.
### Arguments
- Execute a simple command with an absolute path like `/bin/ls` with arguments but without any quotes or double quotes.
### `echo`
- `echo` command with or without arguments, or the `-n` option.
	> -n     do not output the trailing newline
- Repeat with different arguments.
### `exit`
- `exit` command with or without arguments
- Repeat with different arguments.
### Return value of a process
- Execute a simple command with an absolute path like `/bin/ls` with arguments but without any quotes or double quotes.
	- Then execute `echo $?`.
	- Repeat with different commands and arguments. And wrong commands like `/bin/ls nofile`.
	- Try anything like `expr $? + $?`.
	> The `expr` command in Unix evaluates a given expression and displays its corresponding output.
### Signals
- `ctrl-C` in an empty prompt should display a new line with a new prompt.
- `ctrl-\` in an empty prompt should not do anything.
- `ctrl-D` in an empty prompt should quit minishell.
- `ctrl-C` in a prompt after writing something should display a new line with a new prompt.
	- Buffer should be clean. Nothing from the previous line should be executed when `Enter` is pressed.
- `ctrl-D` in a prompt after something is written should not do anything.
- `ctrl-\` in a prompt after something is written should not do anything.
- Try all after running a blocking command like `cat` without arguments or `grep "something"`.
### Double quotes
- Execute a simple command with arguments using double quotes (including whitespaces).
- Try `echo "cat file.c | cat > file.c"`
### Single quotes
- Execute commands with single quotes as arguments
- Try empty arguments.
- Try environment variables, whitespaces, pipes, redirection in the single quotes.
- `echo '$USER'` must print "$USER".
- Nothing should be interpreted.
> Single quotes won't interpolate anything, but double quotes will. For example: variables, backticks, certain \ escapes, etc.
>
> Example:
>
> ` echo "$(echo "upg")"`
>
> upg
>
> `$ echo '$(echo "upg")'`
>
> $(echo "upg")
## 2. Builtin Commands
### `env`
- `env` should show the current environment variables.
### `unset`
- Export environment variables, create new ones and replace old ones.
- Use unset to remove some of them.
- Check the result with env.
>The `unset` command removes any settings to the value of an option, which reverts the option to the factory default value. Some options are predefined and read-only, and cannot be unset.
### `cd`
- Use the command `cd` to move the working directory and check if you are in the right directory with `/bin/ls`.
- Try `'.'` and `'..'` as arguments.
### `pwd`
- Try `pwd` command in different directories.
## 3. Path
### Relative path
- Execute commands with using relative paths.
- Try in different directories with a complex relative path (lots of ..).
### Environment path
- Execute commands without any path (`ls`, `wc`, `awk` and so forth).
- The commands should not work after unset the `$PATH`.
- Set the `$PATH` to a multiple directory value (`directory1:directory2`) and ensure that directories are checked in order from left to right.
## 4. Redirection and Pipes
### Redirection
- Execute commands with redirections `<` and/or `>`
Repeat multiple times with different commands and arguments and sometimes change `>` with `>>`
- Check if multiple tries of the same redirections fail.
- Test `<<` redirection (it doesn't have to update the history).
### Pipes
- Execute commands with pipes like `cat file | grep bla | more`
- Repeat multiple times with different commands and arguments.
- Try some wrong commands like `ls filethatdoesntexist | grep bla | more`
- Try to mix pipes and redirections.
## 5. History and Environment Variables
### History
- Type a command line, then use `ctrl-C` and press `Enter`. The buffer should be clean and there should be nothing left to execute.
	- It should be possible to navigate through history using Up and Down.
- minishell should not crash and print an error when commands that should not work like `dsbdghsd` are executed.
- `cat | cat | ls` should behave in a "normal way".
- Execute a long command with a ton of arguments.
### Environment variables
- Execute `echo` with some environment variables (`$variable`) as arguments.
	- Check that `$` is interpreted as an environment variable.
	- Check that double quotes interpolate `$`.
	- Check that `USER` exists. Otherwise, set it.
	- `echo "$USER"` should print the value of the `USER` variable.
	- `echo '"$USER"'` should print "$USER".
## 6. Bonus
### And, Or
- Use `&&`, `||` and parenthesis with commands and ensure minishell behaves the same way bash does.
### Wildcard
- Use wildcards in arguments in the current working directory.