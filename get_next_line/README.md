##### *This project has been created as part of the 42 curriculum by `<csahyoun>.`*

# Description

The `get_next_line` project implements a function that reads a line from a file descriptor.
Its goal is to practice file I/O, dynamic memory allocation, and string manipulation in C.
The function can read from both files and standard input (terminal), returning one line per call until EOF.

This library provides the function:

```c
char	*get_next_line(int fd)
```

# Instructions

A main function will be written and can be put into a `main.c` file for testing:

```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    // Example 1: Reading from a file
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s", line);
        free(line);
    }
    close(fd);

    // Example 2: Reading from standard input (terminal)
    printf("\nType something (Ctrl+D to end):\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("You typed: %s", line);
        free(line);
    }

    return (0);
}
```

Compile with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
./a.out
```

# Algorithm Explanation

### The algorithm uses:

* A static stash to store leftover data between calls.
* A read loop that fills a buffer until a newline or EOF is found.
* **Helper functions(**`ft_strjoin`, `ft_substr`, `ft_strdup`, `ft_strchr`**)** to manage strings safely.
* Two key helpers:
  * `extract_line`: returns the next line from the stash.
  * `update_leftover`: updates the stash with the remaining data after a line is extracted.

### This approach ensures:

* Efficient reading in chunks(`BUFFER_SIZE`).
* No memory leaks (old stash is freed before reassignment).
* Correct handling of the edge cases (empty files, no new at EOF, interactive input).

# Resources

### References

* Youtube videos:
  * C file I/O basics
* C standard library documentation for `read`.

### AI Usage

AI was used for:

* Explaining how the `get_next_line` function flow should work and what edge cases to look out for.
* Structuring and drafting this README template.
* Clarifying documentation and explaining algorithmic choices in plain language.
* Brainstorming how to present the project clearly.

All implementation, debugging, and code logic were done manually.
