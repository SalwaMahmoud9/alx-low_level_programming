#include "main.h"
/**
 * read_textfile - read text file
 * @filename: file name
 * @letters: letters in file
 * Return: printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	int fd, printed, wrote;

	buff = malloc(letters);
	if (buff == NULL)
		return (0);
	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDWR);
	if (fd == -1)
		return (0);
	printed = read(fd, buff, letters);
	if (printed == -1)
		return (0);
	wrote = write(STDOUT_FILENO, buff, printed);
	if (wrote == -1)
		return (0);
	if (close(fd) == -1)
		return (0);
	free(buff);
	return (printed + '\n');
}
