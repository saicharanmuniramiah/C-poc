# In-Memory File System in C

## Project Overview
This project simulates a basic file system in memory using the C programming language. It supports essential file operations such as creating files and directories, navigating through directories, editing file content, and managing permissions. The project is modularized for better organization and maintainability.

## Features
- Create and manage files and directories
- Navigate through directories
- Write content to files
- Display file content
- Change file and directory permissions
- List contents of the current directory
- Print the current directory path

## File Structure
- `fs_node.h`: Defines the FSNode structure
- `fs_node.c`: Node creation and management
- `commands.h`: Command declarations
- `commands.c`: Command implementations
- `main.c`: Main program logic and user interaction
- `Makefile`: For compiling the project

## Compilation Instructions
To compile the project, use the provided Makefile. Run the following command in the terminal:

```bash
make
