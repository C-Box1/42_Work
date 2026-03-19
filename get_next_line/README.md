##### *This project has been created as part of the 42 curriculum by `<csahyoun>`.*

# Description

The `get_next_line` and `get_next_line_bonus` projects implement a function that reads a line from a file descriptor.
Their goal is to practice file I/O, dynamic memory allocation, and string manipulation in C.
The function can read from both files and standard input (terminal), returning one line per call until EOF.

This library provides the function:

```c
char	*get_next_line(int fd)
char	*get_next_line_bonus(int fd)
```

Instructions

A main function will be written and can be put into a `main.c` file for testing:

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

int main(void)
{
    int     fd1;
    int     fd2;
    char    *line;

    // === Mandatory test with one file ===
    fd1 = open("testfile.txt", O_RDONLY);
    if (fd1 < 0)
    {
        perror("Error opening testfile.txt");
        return (1);
    }
    printf("=== Testing get_next_line (mandatory) ===\n");
    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd1);

    // === Terminal input test ===
    printf("\n=== Testing get_next_line from terminal (stdin) ===\n");
    printf("Type some lines (Ctrl+D to end):\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("You typed: %s", line);
        free(line);
    }

    // === Bonus test with two files ===
    fd1 = open("testfile.txt", O_RDONLY);
    fd2 = open("testfile2.txt", O_RDONLY);
    if (fd1 < 0 || fd2 < 0)
    {
        perror("Error opening test files");
        return (1);
    }
    printf("\n=== Testing get_next_line_bonus (two FDs) ===\n");
    while (1)
    {
        line = get_next_line(fd1);
        if (!line)
            break;
        printf("File1: %s", line);
        free(line);

        line = get_next_line(fd2);
        if (!line)
            break;
        printf("File2: %s", line);
        free(line);
    }
    close(fd1);
    close(fd2);

    return (0);
}
```

### How to compile and run every test:

Mandatory test:

* Create a file called `testfile.txt` with several lines of text written inside
* Compile with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

* Run with:

  ```bash
  ./gnl_test
  ```

Terminal test:

* You can compile with either mandatory or bonus sources (both work for stdin):

```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line.c get_next_line_utils.c main.c -o gnl_stdin_test
```

* Run with:

```bash
./gnl_stdin_test
```

Bonus test:

* Create two files, `testfile.txt` and `testfile2.txt` with several lines written in each file
* Compile with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus_test
```

* Run with:

  ```bash
  ./gnl_bonus_test
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
