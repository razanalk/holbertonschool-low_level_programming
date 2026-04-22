#ifndef MAIN_H
#define MAIN_H

HEAD
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

ssize_t read_textfile(const char *filename, size_t letters);

#include <stddef.h>
#include <sys/types.h>

/* Task 0 */
ssize_t read_textfile(const char *filename, size_t letters);

/* Task 1 */
int create_file(const char *filename, char *text_content);

/* Task 2 */
int append_text_to_file(const char *filename, char *text_content);

/* Task 3 */
int cp(char *file_from, char *file_to);

#endif
