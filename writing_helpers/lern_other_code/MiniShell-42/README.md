# 🐚 MiniShell

Welcome to the **MiniShell** project! This project is a collaborative effort between **mjakowic** and **dtoszek** to create a basic shell program in C. The MiniShell is designed to replicate some of the core functionalities of a typical UNIX shell, allowing users to interact with their system's command-line interface.

## 📚 Table of Contents

- [📖 Introduction](#introduction)
- [✨ Features](#features)
- [⚙️ Installation](#installation)
- [🚀 Usage](#usage)
- [🔧 Built-in Commands](#built-in-commands)
- [👥 Contributors](#contributors)
- [📜 License](#license)

## 📖 Introduction

MiniShell is a lightweight shell built from scratch using the C programming language. The goal of this project was to gain a deeper understanding of how command-line interpreters work, including how they manage processes, handle input/output, and parse commands.

## ✨ Features

- 🛠️ Basic command execution
- 📤 Input/output redirection
- 🔗 Piping between commands
- 🌐 Environment variable management
- 🛡️ Signal handling (e.g., `Ctrl+C`)
- 🏗️ Built-in commands (like `cd`, `exit`, etc.)
- 🚨 Error handling and reporting

## ⚙️ Installation

To build the MiniShell, you'll need to have a C compiler (like `gcc`) installed on your system.

1. 📥 Clone the repository:
    ```bash
    git clone https://github.com/Jakowicki/MiniShell.git
    cd minishell
    ```

2. 🛠️ Compile the project:
    ```bash
    make
    ```

3. 🚀 Run the MiniShell:
    ```bash
    ./minishell
    ```

## 🚀 Usage

Once you have the MiniShell running, you can start typing commands as you would in a typical UNIX shell. Here are a few examples:

- Running a command:
    ```bash
    ls -la
    ```

- Using pipes:
    ```bash
    ls -la | grep txt
    ```

- Redirecting output to a file:
    ```bash
    echo "Hello, World!" > hello.txt
    ```

- Using built-in commands:
    ```bash
    cd /path/to/directory
    ```

## 🔧 Built-in Commands

MiniShell includes several built-in commands:

- `cd` - Change the current directory
- `exit` - Exit the shell
- `env` - Display environment variables
- `setenv` - Set an environment variable
- `unsetenv` - Unset an environment variable

## 👥 Contributors

This project was developed by:

- **dtoszek**
- **mjakowic**

## 📜 License

Feel free to work with the code and make it even better while studying. Good luck:)
