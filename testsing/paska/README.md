# get_next_line Project README

## Table of Contents
- [Objectives](#objectives)
- [General Instructions](#general-instructions)
- [Mandatory Part](#mandatory-part)
- [Bonus Part](#bonus-part)
- [Delivery and Evaluation](#delivery-and-evaluation)

---

## Objectives

This project aims to introduce you to a practical function and the concept of static variables in C.

---

## General Instructions

- This project must be written in C.
- Follow the Norm when writing your project. Additional files or functions are included in the Norm's verification, and any norm error will result in a score of 0.
- Your functions must not end unexpectedly (segfault, bus error, double free, etc.), nor exhibit undefined behavior.
- Properly release all heap-allocated memory. Memory leaks are not allowed.
- If required, provide a Makefile that compiles your source files to the required output with the flags -Wall, -Werror, and -Wextra. Your Makefile should not relink.
- Your Makefile should include at least the norms $(NAME), all, clean, fclean, and re.
- For bonus points, create a bonus rule in your Makefile and include all headers, libraries, or functions that are prohibited in the main part of the project. Bonus tasks are evaluated separately from the mandatory part.
- If your project allows the use of the libft, create a directory named "libft" and copy its source and associated Makefile there. Your project's Makefile should first compile the libft library using its Makefile and then compile your project.
- While not mandatory, it's recommended to create test programs for your project to ensure its correctness. These test programs won't be submitted or evaluated, but they can help verify your program's functionality during your and your peers' evaluations.

---

## Mandatory Part

**Function Name:** get_next_line

**Prototype:** `char *get_next_line(int fd);`

**Files to Submit:** get_next_line.c, get_next_line_utils.c, get_next_line.h

**Parameters:** `fd` - File descriptor from which to read

**Return Value:** If successful, the read line; if failed or end of reading, `NULL`

**Authorized Functions:** read, malloc, free

**Description:** Write a function that reads a line from a file descriptor. Calling your function repeatedly (e.g., using a loop) allows you to read the content of the file pointed to by the file descriptor line by line until the end. Your function should return the line that has just been read. If there's nothing more to read or an error occurs, it should return `NULL`. Ensure that your function behaves correctly when reading from a file and when reading from stdin. The returned line should end with a newline character, except if the end of the file is reached and it doesn't end with a newline character.

---

## Bonus Part

For the bonus part, develop the following:

- Develop `get_next_line()` with a single static variable.
- Make `get_next_line()` capable of handling multiple file descriptors simultaneously. This means you should be able to alternate between different file descriptors (e.g., 3, 4, and 5) and use `get_next_line()` on each of them without losing the reading context of each descriptor.

To complete the bonus part, create the following files in addition to the mandatory ones:

- get_next_line_bonus.c
- get_next_line_bonus.h
- get_next_line_utils_bonus.c

The bonus part will only be evaluated if the mandatory part is completed perfectly.

---

## Delivery and Evaluation

Submit your project in your assigned Git repository. Only the content in your Git repository will be evaluated. Double-check your filenames for correctness.

During the project, keep in mind:

1) Both the buffer size and line size can have very different values.
2) A file descriptor (fd) doesn't exclusively point to regular files.

Be smart and compare and verify your solutions with your peers. Prepare a set of tests for evaluation. Once you pass, consider adding your `get_next_line()` to your libft.