# 42cursus' get_next_line

Development repository for the 42cursus' get_next_line project.

For more information about 42cursus and its projects, please refer to the [42cursus repository](https://github.com/42cursus).

## About
The aim of this project is to code a function that returns a line ending with a newline, read from a file descriptor.

### TLDR
This project involves coding a function that returns one line at a time from a text file.

## Index
- [get_next_line](#get_next_line): source code developed for the project.

## get_next_line

### Functions
- **ft_result**: Gets the line before the newline.
- **ft_get_line**: Returns the index of the newline if found else returns -1.
- **ft_add**: reinitialize the static variable.
- **get_next_line**: Main function.

## get_next_line_utils

### Functions
- **ft_strdup**: Save a copy of a string (with malloc).
- **ft_calloc**: Allocates X size of memory and set it to 0.
- **ft_strlen**: Find the length of a string.
- **ft_strjoin**: Joins 2 strings together.

## Usage

### Requirements
The function is written in the C language and thus needs the gcc compiler and some standard C libraries to run.

### Instructions

#### 1. Using it in your code
To use the function in your code, simply include its header:

```
#include "get_next_line.h"
and, when compiling your code, add the source files and the required flag:

get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
If you're on Linux, you may as well need the following flags:

-D ARG_MAX="sysconf(_SC_ARG_MAX)" -D OPEN_MAX=1024
#### Third-party testers
gnlTester
mrjvs/42cursus_gnl_tests
Hellio404/Get_Next_Line_Tester
saarikoski-jules/gnl_unit_tests
charMstr/GNL_lover
Mazoise/42TESTERS-GNL
#### Notes
static keyword
Making a global variable/function static: only visible within its own translation unit.
static (local variable): presistent across function calls and only visible within its function.
note: you cant use the same name for static variable and global static variable! but never do it
