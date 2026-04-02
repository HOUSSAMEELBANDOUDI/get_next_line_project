# get_next_line — 42 Project

A function that reads a file **line by line** from a file descriptor. Built as part of the 42 school curriculum, this project teaches static variables and efficient file reading with a configurable buffer size.

## Function Prototype

```c
char *get_next_line(int fd);
```

## Usage

```c
#include "get_next_line.h"

int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## Bonus Features

- Handle multiple file descriptors simultaneously
- Only one static variable used

## Compile with custom buffer size

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

## Tech Stack

- **C**
- **Static variables**
- **File I/O** (read, open, close)

## Author

**Houssame El Bandoudi** — [GitHub](https://github.com/HOUSSAMEELBANDOUDI) | 42 Student (hel-band)
