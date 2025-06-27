# 📖 get_next_line

A C function that reads a file line by line, one line at a time. This project is part of the 42/Codam curriculum and focuses on file descriptor management, static variables, and memory management.

## 🎯 Project Overview

The `get_next_line` function allows you to read a file line by line without knowing the file size beforehand. It's particularly useful for reading large files efficiently without loading the entire content into memory.

### Key Features

- 📄 **Line-by-line reading**: Read one line at a time from any file descriptor
- 🎛️ **Configurable buffer size**: Adjustable `BUFFER_SIZE` for optimal performance
- 🔄 **Multiple file descriptor support**: Bonus version handles multiple files simultaneously
- 💾 **Memory efficient**: Only stores what's necessary using static variables
- 🛡️ **Error handling**: Robust error checking and memory leak prevention

## 🛠️ Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters
- `fd`: The file descriptor to read from

### Return Value
- Returns the line that was read (including the `\n` character if present)
- Returns `NULL` when there's nothing more to read or if an error occurs

## 📁 Files

### Mandatory Part
- `get_next_line.c` - Main function implementation
- `get_next_line.h` - Header file with function prototypes
- `get_next_line_utils.c` - Utility functions

### Bonus Part
- `get_next_line_bonus.c` - Enhanced version supporting multiple file descriptors
- `get_next_line_bonus.h` - Header file for bonus implementation
- `get_next_line_utils_bonus.c` - Utility functions for bonus

> **Developer's Note**: The bonus was so straightforward that I practically implemented it by changing a single line from `static char *saved_str;` to `static char *saved_str[OPEN_MAX];` and adding `[fd]` everywhere. Sometimes the simplest solutions are the most elegant! 😄

## 🚀 Compilation

### Basic compilation:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

### With bonus:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

### Custom buffer size:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1000 get_next_line.c get_next_line_utils.c
```

## 💡 Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

### Multiple File Descriptors (Bonus)

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2;
    char *line1, *line2;
    
    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    
    // Read alternately from both files
    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
    
    printf("File 1: %s", line1);
    printf("File 2: %s", line2);
    
    free(line1);
    free(line2);
    close(fd1);
    close(fd2);
    return (0);
}
```

## 🔧 Technical Implementation

### Core Algorithm
1. **Read from file descriptor** into a buffer of size `BUFFER_SIZE`
2. **Store overflow** in a static variable for subsequent calls
3. **Extract line** up to the first newline character
4. **Return the line** and save the remainder for the next call

### Key Functions

#### Main Functions
- `get_next_line(int fd)` - Main function that returns the next line
- `ft_read_line(int fd, char *saved_str)` - Reads and concatenates data until newline or EOF
- `ft_trim_str(char *str, int saved)` - Splits string at newline character

#### Utility Functions
- `ft_strjoin(char *s1, const char *s2)` - Concatenates two strings
- `ft_strchr(const char *s, int c)` - Locates character in string
- `ft_strdup(const char *s1)` - Duplicates a string
- `ft_strlen(const char *line)` - Calculates string length
- `ft_free(char *str)` - Safely frees memory and returns NULL

### Buffer Size Impact
- **Small buffer** (1-10): More system calls, slower but less memory usage
- **Large buffer** (1000+): Fewer system calls, faster but more memory usage
- **Optimal range**: Usually between 32-1024 depending on use case

## 🧪 Testing

The function handles various edge cases:
- ✅ Empty files
- ✅ Files without newlines
- ✅ Very long lines
- ✅ Binary files
- ✅ Multiple consecutive newlines
- ✅ Invalid file descriptors
- ✅ Memory allocation failures

## 📊 Performance Characteristics

- **Time Complexity**: O(n) where n is the length of the line
- **Space Complexity**: O(BUFFER_SIZE + line_length)
- **Memory Leaks**: Zero (when used correctly with proper `free()` calls)

## 🎓 Learning Outcomes

This project taught me:
- File descriptor manipulation and I/O operations
- Static variable usage and lifetime management
- Dynamic memory allocation and deallocation
- Buffer management and string manipulation
- Error handling and edge case management
- The importance of reading documentation (looking at you, `read()` function!)

## 📝 Project Constraints

- Must use only `read()`, `malloc()`, and `free()` functions
- No global variables allowed
- All memory must be properly freed
- Must handle multiple file descriptors simultaneously (bonus)
- Must work with any buffer size > 0

## 🤝 Contributing

This is a school project, but feel free to:
- Report bugs or issues
- Suggest optimizations
- Use it as a reference for your own implementation

## 📜 License

This project is part of the 42/Codam curriculum. Feel free to use it for educational purposes.

---

**Made with ☕ and countless segfaults at Codam Amsterdam**

*"Why read the whole book when you can read it line by line?" - Ancient Developer Proverb*
