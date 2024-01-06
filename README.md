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
- **get_reminder**: Gets the reminder after the newline.
- **check_newline**: Returns the index of the newline if found else returns -1.
- **ft_strlen**: Find the length of a string.
- **get_next_line**: Main function.

## get_next_line_utils

### Functions
- **ft_strdup**: Save a copy of a string (with malloc).
- **ft_calloc**: Allocates X size of memory and set it to 0.
- **ft_strjoin**: Joins 2 strings together.

## Usage

### Requirements
The function is written in the C language and thus needs the gcc compiler and some standard C libraries to run.

### Instructions

#### 1. Using it in your code
To use the function in your code, simply include its header:

```c
#include "get_next_line.h"
