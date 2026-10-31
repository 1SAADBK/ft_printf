*This project has been created as part of the 42 curriculum by sbenkass.*

# ft_printf

## Description :

The ft_printf project is a custom implementation of the standard C library function printf. The goal of this project is to recreate the formatting engine from scratch, handling various data types and converting them into a printed output.

Through this project, I explored the use of variadic arguments in C (using the stdarg.h library) and deepened my understanding of how memory and data types are managed at a low level.

## Instructions :

### 1. Compilation

To compile the library, navigate to the project root and run `make`. This will generate the libftprintf.a static library file.

### 2. Integration

To use the function in your own C projects, include the header file in your source code:

```c
#include "ft_printf.h"
```

### 3. Compiling your Project

When compiling your project, make sure to link the generated library. For example, if your file is named main.c, use the following command:

```bash
cc main.c libftprintf.a -o my_program
```

### 4. Cleaning Up

| Command | Action |
| :--- | :--- |
| `make clean` | Removes all object files (`.o`). |
| `make fclean` | Removes object files and the `libftprintf.a` library. |
| `make re` | Performs a full re-compile (fclean + make). |

## Resources :

The development of ft_printf was supported by a variety of learning materials and collaborative efforts:
### Peer Collaboration

    1337 students: A special thanks to my peers at 1337 School for the insightful code reviews and logic brainstorming sessions.

### Documentation & Web

    GeeksforGeeks: Used for deep dives into C data types and memory management.

    GitHub: Utilized as a reference for project instructions, requirements, and community-standard documentation.

### Artificial Intelligence

AI played a role as a personalized tutor and development assistant in the following areas:

    Variadic Functions: I utilized AI to learn the mechanics of the <stdarg.h> library, specifically how to properly implement va_list, va_start, va_arg, va_copy, and va_end.

    Debugging: Used AI to help analyze and resolve specific bugs within the code logic.

    Documentation: AI assisted in structuring and refining this README.md to ensure professional clarity.


## Algorithm and Data Structure

The architecture of ft_printf is designed around a single-pass parsing algorithm coupled with direct output writing. The goal was to minimize memory allocation and ensure modularity.
### 1. Variadic Argument Handling (va_list)

The core data structure used in this project is the va_list (from <stdarg.h>). Since printf must accept an undefined number of arguments of varying types, va_list is the standard C mechanism to traverse the stack frame where these arguments are stored.

    Initialization: va_start initializes the pointer to the first argument.

    Retrieval: va_arg retrieves the next argument based on the type specified (e.g., int, char *, unsigned long long).

    Cleanup: va_end cleans up the memory pointers before the function returns.

### 2. The Parsing Loop (The Algorithm)

The main ft_printf function operates as a dispatcher. It iterates through the input format string character by character:

    Standard Characters: If the current character is not a %, it is immediately written to the standard output (file descriptor 1), and the length counter is incremented.

    Format Specifiers: If a % is encountered:

        The algorithm inspects the next character to identify the type (cspdiuxX%).

        It triggers a Dispatch Logic (via printvariable) to call the appropriate helper function (e.g., printf_str, printf_hexa).

        The iterator skips the format specifier to avoid printing it as text.

### 3. Recursive Number Conversion

A key algorithmic choice in this implementation is the use of recursion for printing numeric types (%d, %i, %u, %x, %X, %p).

Instead of using malloc to create a string buffer (like itoa) or a fixed-size buffer, the code uses stack recursion to resolve digits:

    Divide: The number is repeatedly divided by the base (10 for decimal, 16 for hex).

    Conquer: The recursion dives until the number is less than the base (the most significant digit).

Justification:

    Memory Efficiency: No heap allocation is required.

    Simplicity: Recursion naturally handles the "reverse" order of digit extraction (printing 123 instead of 321) without needing a temporary array to reverse the string.

### 4. Return Value Management

Per the standard library requirement, the function maintains a len (length) counter. Every write operation, whether inside the main loop or a helper function, returns the number of bytes written. These are accumulated and returned at the end, ensuring ft_printf correctly reports the total length of the printed string.