#include "main.h"
/**
 * main - main
 * @count: count
 * @arr: array
 * Return: 0
 */
int main(int count, char **arr)
{
	int fdFrum, fdToo, wrote, readed;
	char buff[1024];

	fdFrum = open(arr[1], O_RDONLY);
	fdToo = open(arr[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (count != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	if (fdFrum == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", arr[1]);
		exit(98);
	}
	if (fdToo == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", arr[2]);
		exit(99);
	}
	while ((readed = read(fdFrum, buff, 1024)) > 0)
	{
		wrote = write(fdToo, buff, readed);
		if (wrote == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", arr[2]);
			exit(99);
		}
	}
	if (readed == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", arr[1]);
		exit(98);
	}
	if (close(fdFrum) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d", fdFrum);
		exit(100);
	}
	if (close(fdToo) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d", fdToo);
		exit(100);
	}
	return (0);
}
