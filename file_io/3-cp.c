#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * main - copies content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, r, w;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(1, "Usage: cp file_from file_to\n");
		_exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(1, "Error: Can't read from file %s\n", argv[1]);
		_exit(98);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(1, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		_exit(99);
	}

	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
		{
			dprintf(1, "Error: Can't write to %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			_exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(1, "Error: Can't read from file %s\n", argv[1]);
		close(fd_from);
		close(fd_to);
		_exit(98);
	}

	if (close(fd_from) == -1)
	{
		dprintf(1, "Error: Can't close fd %d\n", fd_from);
		_exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(1, "Error: Can't close fd %d\n", fd_to);
		_exit(100);
	}

	return (0);
}
