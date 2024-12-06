<h1 align="center"><a href="https://github.com/f-corvaro/MINISHELL">
	<img src="https://github.com/f-corvaro/MINISHELL/blob/main/.extra/minishell.png" alt="MINISHELL">
  </a></h1>

<p align="center">
	<b><i>"Explore the intricacies of shell programming with Minishell, a simplified shell implementation."</i></b><br>
</p>
<p align="center" style="text-decoration: none;">
    <a href="https://github.com/f-corvaro/MINISHELL/blob/main/.extra/en.subject.pdf"><img alt="subject" src="https://img.shields.io/badge/subject-MINISHELL-yellow" /></a>
    <a href="https://github.com/f-corvaro/MINISHELL"><img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/f-corvaro/MINISHELL?color=blueviolet" /></a>
    <a href="https://github.com/f-corvaro/MINISHELL"><img alt="Code language count" src="https://img.shields.io/github/languages/count/f-corvaro/MINISHELL?color=yellow" /></a>
    <a href="https://github.com/f-corvaro/MINISHELL"><img alt="GitHub top language" src="https://img.shields.io/github/languages/top/f-corvaro/MINISHELL?color=blueviolet" /></a>
    <a href="https://github.com/f-corvaro/MINISHELL"><img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/f-corvaro/MINISHELL?color=yellow" /></a>
</p>

<h3 align="center">Index</h3>
<p align="center">
 <a href="#introduction">Introduction</a><br>
 <a href="#overview">Overview</a><br>
 <a href="#folder-structure">Folder Structure</a><br>
 <a href="#project-requirements---mandatory-part">Project Requirements - Mandatory Part</a><br>
 <a href="#important-guidelines">Important Guidelines</a><br>
 <a href="#specific-rules-for-the-mandatory-part">Specific Rules for the Mandatory Part</a><br>
 <a href="#program-name">Program name</a><br>
 <a href="#usage">Usage</a><br>
 <a href="#files-to-submit">Files to Submit</a><br>
 <a href="#allowed-external-functions">Allowed External Functions</a><br>
 <a href="#project-requirements---bonus-part">Project Requirements - Bonus Part</a><br>
 <a href="#memory-leaks-and-readline">Memory Leaks and `readline()`</a><br>
 <a href="#theoretical-background">Theoretical Background</a><br>
 <a href="#shell">Shell</a><br>
 <a href="#testing-tools-for-the-minishell-project">Testing Tools for the minishell Project</a><br>
 <a href="#evaluation-process">Evaluation Process</a><br>
 <a href="#correction-sheet">Correction sheet</a><br>
 <a href="#developed-skills">Developed Skills</a><br>
 <a href="#acknowledgments">Acknowledgments</a><br>
 <a href="#support">Support</a><br>
 <a href="#references">References</a><br>
 <a href="#author">Author</a><br>
</p>

## Introduction

<p align="justify">

The Minishell project is a collaborative project undertaken at 42 school. It serves as an introduction to shell programming and aims to provide students with a deeper understanding of the intricacies of shell implementation. The project is designed to be completed by a team of two students, improving collaboration and teamwork skills. Personally, I completed this project with my teammate [@ffursini](https://github.com/ffursini).

</p>
<br>

### Overview

<p align="justify">

Through the development of Minishell, students gain hands-on experience in building a simplified shell. This project involves parsing commands, executing processes, handling input/output redirection, and managing pipelines. It serves as a stepping stone for students to explore system programming and gain a solid foundation in shell scripting.

Key Concepts Covered in Minishell:

- **Unix Shell Basics**: Understanding command execution, environment variables, and shell scripting.
- **Process Management**: Knowledge of process creation, management, and termination using system calls like `fork()`, `exec()`, and `wait()`.
- **File Descriptors and Redirection**: Understanding file descriptors, standard input/output, and using operators like `>`, `<`, and `|` for input/output redirection.
- **Pipes and Inter-Process Communication (IPC)**: Learning how to use pipes for communication between processes.
- **Signal Handling**: Handling signals in a Unix environment, including common signals like `SIGINT`, `SIGQUIT`, and `SIGTERM`.
- **Built-in Commands**: Implementing built-in shell commands such as `cd`, `echo`, `exit`, `env`, `setenv`, `unsetenv`, etc.
- **Error Handling**: Properly handling errors and edge cases in a shell environment.
- **Memory Management**: Efficiently managing memory allocation and deallocation to avoid leaks and ensure stability.
- **Parsing and Tokenization**: Techniques for parsing and tokenizing user input to interpret and execute commands correctly.
- **Concurrency**: Understanding concurrent execution and managing multiple processes running simultaneously.
- **Shell Scripting**: Basics of writing and executing shell scripts to automate tasks.
- **History and Job Control**: Implementing features like command history and job control (background and foreground processes).

</p>
<br>

## Folder Structure

<p align="justify">

```
.
├── minishell
│   ├── include
│   │   ├── functions.h
│   │   ├── globals.h
│   │   ├── minishell.h
│   │   ├── prompt.h
│   │   └── types.h
│   ├── libft
│   ├── srcs
│   │   ├── builtins
│   │   │   ├── cd.c
│   │   │   ├── echo.c
│   │   │   ├── env.c
│   │   │   ├── exit.c
│   │   │   ├── export.c
│   │   │   ├── pwd.c
│   │   │   └── unset.c
│   │   ├── environment
│   │   │   └── env_handler.c
│   │   ├── errors
│   │   │   └── error.c
│   │   ├── execution
│   │   │   ├── builtin_commands.c
│   │   │   ├── command_execution.c
│   │   │   ├── execute.c
│   │   │   ├── io_redir.c
│   │   │   └── pipe_management.c
│   │   ├── filesystem
│   │   │   └── file_operations.c
│   │   ├── io
│   │   │   └── input_handler.c
│   │   ├── parser
│   │   │   ├── command_utils.c
│   │   │   ├── command_utils2.c
│   │   │   ├── command.c
│   │   │   ├── dollar_sign_utils.c
│   │   │   ├── dollar_sign.c
│   │   │   ├── parser.c
│   │   │   ├── token_remove.c
│   │   │   ├── token_type.c
│   │   │   ├── tokenizer_utils.c
│   │   │   └── tokenizer.c
│   │   ├── signals
│   │   │   └── signal_handlers.c
│   │   ├── utils
│   │   │   ├── cleanup.c
│   │   │   ├── initialization.c
│   │   │   └── memory_utils.c
│   │   └── main.c
│   └── Makefile
```
</p>

## Project Requirements - Mandatory Part

<p align="justify">

### Important Guidelines

<p align="justify">

- The project must be written in C, following the Norm guidelines.
- Your functions should handle errors gracefully and avoid unexpected crashes or memory leaks.
- All dynamically allocated memory must be properly freed when no longer needed.
- Include a Makefile that compiles your source files with the flags -Wall, -Wextra, and -Werror. Use the cc compiler, and ensure that your Makefile does not relink. It should include the rules $(NAME), all, clean, fclean, and re. You can earn bonus points for additional rules.

</p>

### Specific Rules for the Mandatory Part

<p align="justify">

Your shell should:
 - Display a prompt when waiting for a new command.
 - Have a working history.
 - Search and launch the correct executable based on the `PATH` variable or using a relative or absolute path.
 - **To ensure program stability and integrity, it is recommended to avoid using more than one global variable to indicate a received signal. This approach prevents the signal handler from accessing main data structures.** (This global variable cannot provide any other information or data access than the number of a received signal. It is forbidden to use "norm" type structures in global).
 - Not interpret unclosed quotes or special characters which are not required by the subject such as `\` (backslash) or `;` (semicolon).
 - Handle `’` (single quote) which should prevent the shell from interpreting the meta- characters in the quoted sequence.
 - Handle `"` (double quote) which should prevent the shell from interpreting the meta-
characters in the quoted sequence except for `$` (dollar sign).
 - Implement redirections:
   ◦`<` should redirect input.
   ◦`>` should redirect output.
   ◦`<<` should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
   ◦`>>` should redirect output in append mode.
 - Implement pipes `|` character. The output of each command in the pipeline is connected to the input of the next command via a pipe.
 - Handle environment variables `$` followed by a sequence of characters, which should expand to their values.
 - Handle `$?` which should expand to the exit status of the most recently executed
foreground pipeline.
 - Handle `ctrl-C`, `ctrl-D` and `ctrl-\` which should behave like in bash.
 - In interactive mode:
   ◦`ctrl-C` displays a new prompt on a new line.
   ◦`ctrl-D` exits the shell.
   ◦vctrl-\v does nothing.
 - Your shell must implement the following builtins:
   ◦`echo` with option `-n`
   ◦`cd` with only a relative or absolute path
   ◦`pwd` with no options
   ◦`export` with no options
   ◦`unset` with no options
   ◦`env` with no options or arguments
   ◦`exit` with no options

For any doubt about a requirement, take bash as a reference.

</p>

### Program name
 
 `minishell`

 #### Usage

 ```bash
 ./minishell
 ```

### Files to Submit

 To complete the project, you need to submit the following files:

 - `Makefile`: The makefile that compiles the project's source files.
 - `*.h`: Any header files used in the project.
 - `*.c`: All the source code files for the project.

### Allowed External Functions

- **Readline library functions**:
  - `readline`: Reads a line from the terminal.
  - `rl_clear_history`: Clears the history list.
  - `rl_on_new_line`: Handles the cursor position when a new line is entered.
  - `rl_replace_line`: Replaces the current line with a new one.
  - `rl_redisplay`: Redisplays the current input line.
  - `add_history`: Adds a line to the history list.

- **Standard I/O functions**:
  - `printf`: Prints formatted output to stdout.
  - `write`: Writes data to a file descriptor.

- **Memory management functions**:
  - `malloc`: Allocates memory dynamically.
  - `free`: Frees dynamically allocated memory.

- **File and directory operations**:
  - `access`: Checks a file's accessibility.
  - `open`: Opens a file.
  - `read`: Reads data from a file descriptor.
  - `close`: Closes a file descriptor.
  - `unlink`: Deletes a name and possibly the file it refers to.
  - `opendir`: Opens a directory stream.
  - `readdir`: Reads a directory entry.
  - `closedir`: Closes a directory stream.
  - `stat`: Retrieves information about a file.
  - `lstat`: Retrieves information about a file, without following symbolic links.
  - `fstat`: Retrieves information about an open file.

- **Process management functions**:
  - `fork`: Creates a new process.
  - `wait`: Waits for a child process to change state.
  - `waitpid`: Waits for a specific child process to change state.
  - `wait3`: Waits for a child process to change state and returns resource usage information.
  - `wait4`: Waits for a specific child process to change state and returns resource usage information.
  - `execve`: Executes a program.
  - `exit`: Terminates the calling process.

- **Signal handling functions**:
  - `signal`: Sets a signal handler.
  - `sigaction`: Examines and changes a signal action.
  - `sigemptyset`: Initializes a signal set to exclude all signals.
  - `sigaddset`: Adds a signal to a signal set.
  - `kill`: Sends a signal to a process.

- **Terminal control functions**:
  - `isatty`: Tests whether a file descriptor refers to a terminal.
  - `ttyname`: Returns the name of the terminal associated with a file descriptor.
  - `ttyslot`: Returns the index of the current user's terminal.
  - `ioctl`: Controls device parameters.
  - `tcsetattr`: Sets the parameters associated with the terminal.
  - `tcgetattr`: Gets the parameters associated with the terminal.

- **Environment functions**:
  - `getenv`: Retrieves the value of an environment variable.

- **Path and directory functions**:
  - `getcwd`: Gets the current working directory.
  - `chdir`: Changes the current working directory.

- **Error handling functions**:
  - `strerror`: Returns a string describing the error code.
  - `perror`: Prints a description for the last error that occurred.

- **Terminal capability functions**:
  - `tgetent`: Loads the terminal entry.
  - `tgetflag`: Gets a boolean terminal capability.
  - `tgetnum`: Gets a numeric terminal capability.
  - `tgetstr`: Gets a string terminal capability.
  - `tgoto`: Computes a cursor movement string.
  - `tputs`: Outputs a terminal capability string.

 Please note that the use of the `ft_printf` or other functions from the Libft library is authorized. 

</p>

## Project Requirements - Bonus Part

<p align="justify">

Your program must implement the following additional features as part of the bonus requirements:

- Support for logical operators `&&` and `||` with parenthesis for priorities.
- Wildcards `*` should work for the current working directory.

The bonus part will only be assessed if the mandatory part is completed perfectly. Perfect completion of the mandatory requirements means that all mandatory features have been implemented without any malfunctions. If you have not passed all the mandatory requirements, your bonus part will not be evaluated.

</p>

## Memory Leaks and `readline()`

<p align="justify">

When using the `readline()` function, it is important to be aware of potential memory leaks. While you are not required to fix these leaks in the `readline()` function itself, it is crucial to ensure that your own code does not have any memory leaks.

</p>

## Theoretical Background

### Shell

<p align="justify">

A shell is a command-line interface that allows users to interact with an operating system. It provides a way to execute commands, manage processes, and manipulate files and directories. Shells are an essential component of Unix-like operating systems and are widely used in the field of system administration and software development.

Minishell is a simplified shell implementation that aims to provide students with a deeper understanding of shell programming. It serves as a stepping stone for exploring the intricacies of shell implementation and system programming. To successfully complete the Minishell project, it is important to have a solid understanding of the following concepts:

- **Command Execution**: Understanding how to execute commands in a shell environment. This involves parsing user input, identifying the command to be executed, and executing it using system calls like `fork()` and `exec()`.

- **Process Management**: Knowledge of process creation, management, and termination. This includes understanding how to create child processes, manage their execution, and handle process synchronization and termination.

- **Input/Output Redirection**: Understanding how to redirect input and output streams in a shell. This involves using operators like `>` and `<` to redirect output to files or read input from files.

- **Pipes and Inter-Process Communication (IPC)**: Learning how to use pipes for communication between processes. This allows for the creation of pipelines, where the output of one command is used as the input for another command.

- **Signal Handling**: Handling signals in a Unix environment. This includes understanding common signals like `SIGINT`, `SIGQUIT`, and `SIGTERM`, and implementing signal handlers to handle these signals appropriately.

- **Built-in Commands**: Implementing built-in shell commands such as `cd`, `echo`, `exit`, `env`, `setenv`, `unsetenv`, etc. These commands are executed directly by the shell without creating a separate process.

- **Error Handling**: Properly handling errors and edge cases in a shell environment. This includes handling command not found errors, syntax errors, and other error conditions that may arise during command execution.

- **Memory Management**: Efficiently managing memory allocation and deallocation to avoid memory leaks and ensure stability. This involves understanding dynamic memory allocation and deallocation functions like `malloc()` and `free()`.

- **Parsing and Tokenization**: Techniques for parsing and tokenizing user input to interpret and execute commands correctly. This includes handling whitespace, quotes, and special characters in user input.

- **Concurrency**: Understanding concurrent execution and managing multiple processes running simultaneously. This includes handling process synchronization, inter-process communication, and managing shared resources.

- **Shell Scripting**: Basics of writing and executing shell scripts to automate tasks. This involves understanding shell scripting languages like Bash and using them to write scripts that can be executed by the shell.

- **History and Job Control**: Implementing features like command history and job control. This includes maintaining a history of executed commands, allowing for command recall and re-execution, and managing background and foreground processes.

- **Exit Code**: Understanding the concept of exit codes in a shell. Exit codes are used to indicate the success or failure of a command execution. A successful command typically has an exit code of 0, while a non-zero exit code indicates an error or failure.

</p>

## Testing Tools for the minishell Project

<p align="justify">

- [minishell_tester by LucasKuhn](https://github.com/LucasKuhn/minishell_tester)
- [minishell_tester by kichkiro](https://github.com/kichkiro/minishell_tester)

**Warning:** To ensure accurate results with the tester, please remember to comment out the `printf("%s", INTRO_MSG);` instruction in the `main.c` file.

</p>

## Evaluation Process

### Correction sheet

<p align="center">
<a href="https://github.com/f-corvaro/MINISHELL/tree/main"><img width="650" src="https://github.com/f-corvaro/MINISHELL/blob/main/.extra/minishell_cs.jpg">

</p>
<br>

## Developed Skills

<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=git,c,vim,vscode" />
  </a>
</p><br>

## Acknowledgments

<p align="justify">

- **[@ffursini](https://github.com/ffursini)**: I would like to express my sincere gratitude to my teammate, for his exceptional assistance and invaluable contributions throughout the development of the Minishell project. His support and collaboration were instrumental in helping me meet the project's tight deadline. I am truly grateful for his dedication and expertise, which greatly contributed to my success at the 42 school.
  
</p>
<br>

## Support

<p align="center">
If you find this repository helpful, please consider starring it to show your support. Your support is greatly appreciated!</p>

<br>

## References

- [42docs: Minishell Project](https://harm-smits.github.io/42docs/projects/minishell): A detailed guide and documentation for the Minishell project provided by 42docs.
- [Medium: Minishell - Building a Mini Bash](https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218): An insightful article on Medium that walks through the process of building a mini Bash shell as part of the 42 curriculum.
- [GNU Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html): The official documentation for the Bash shell, which provides insights into shell behavior and built-in commands.
- [man pages](https://man7.org/linux/man-pages/): The manual pages (`man`) are an essential resource for understanding system calls and library functions in Unix-like operating systems. 
- [GNU Bash Reference Manual](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/): The GNU Bash Reference Manual provides comprehensive documentation for the Bash shell, including information on its behavior, built-in commands, and features. It is a valuable resource for learning and mastering Bash scripting.

<br>

## Author

<p align="center"><a href="https://profile.intra.42.fr/users/fcorvaro"><img style="height:auto;" src="https://avatars.githubusercontent.com/u/102758065?v=4" width="100" height="100"alt=""></a>
<p align="center">
<a href="mailto:fcorvaro@student.42roma.it"><kbd>Email</kbd><alt=""></a>
<a href="https://github.com/f-corvaro"><kbd>Github</kbd><alt=""></a>
<a href="https://www.linkedin.com/in/f-corvaro/"><kbd>Linkedin</kbd><alt=""></a>
<a href="https://42born2code.slack.com/team/U050L8XAFLK"><kbd>Slack</kbd><alt=""></a>

<hr/>