#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

/**
 * get_magic - get magic
 * @ehdr: pointer to struct containing header features
 * @filename: file name
 * @descriptor: descriptor
 */
void get_magic(Elf64_Ehdr *ehdr, char *filename, int descriptor)
{
	size_t i = 0;
	unsigned char *mgc = ehdr->e_ident;

	if (mgc[EI_MAG0] == ELFMAG0 &&
	    mgc[EI_MAG1] == ELFMAG1 &&
	    mgc[EI_MAG2] == ELFMAG2 &&
	    mgc[EI_MAG3] == ELFMAG3)
	{
		printf("Magic:  ");
		while (i < EI_NIDENT)
			printf(" %02x", ehdr->e_ident[i++]);
		printf("\n");
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", filename);
		if (close(descriptor))
			dprintf(STDERR_FILENO, "Problem closing descriptor %d", descriptor);
		exit(98);
	}
}

/**
 * get_class - check class of ELF file
 * @ehdr: pointer to struct of header features
 */
void get_class(Elf64_Ehdr *ehdr)
{
	printf("%-35s", "Class:");
	switch (ehdr->e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("INVALID\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	}
}

/**
 * get_data - get endianness of ELF file
 * @ehdr: pointer to struct of ELF header features
 */
void get_data(Elf64_Ehdr *ehdr)
{
	printf("%-35s", "Data:");
	switch (ehdr->e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("Unknown data format\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little-endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement big-endian\n");
		break;
	}
}

/**
 * get_velf - get version of ELF file
 * @ehdr: pointer to struct of ELF header features
 */
void get_velf(Elf64_Ehdr *ehdr)
{
	printf("%-35s", "Version:");
	switch (ehdr->e_ident[EI_VERSION])
	{
	case EV_NONE:
		printf("%d (invalid)\n", EV_NONE);
		break;
	case EV_CURRENT:
		printf("%d (current)\n", EV_CURRENT);
		break;
	}
}

/**
 * get_osabi - determine which ABI convention is in use
 * @ehdr: pointer to struct of ELF header features
 */
void get_osabi(Elf64_Ehdr *ehdr)
{
	printf("%-35s", "OS/ABI:");
	switch (ehdr->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Stand-alone (embedded)\n");
		break;
	default:
		printf("<unknown: %d>\n", ehdr->e_ident[EI_OSABI]);
	}
}

/**
 * get_vabi - get ABI version
 * @ehdr: pointer to struct of ELF header features
 */
void get_vabi(Elf64_Ehdr *ehdr)
{
	printf("%-35s%d\n", "ABI Version:", ehdr->e_ident[EI_ABIVERSION]);
}

/**
 * get_type - determine file type
 * @ehdr: pointer to struct of ELF header features
 */
void get_type(Elf64_Ehdr *ehdr)
{
	printf("%-35s", "Type:");
	switch (ehdr->e_type)
	{
	case ET_NONE:
		printf("NONE (Unknown type)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	}
}

/**
 * get_entry - determine entry point function address
 * @ehdr: pointer to struct of ELF header features
 */
void get_entry(Elf64_Ehdr *ehdr)
{
	printf("%-35s0x%lx\n", "Entry point address:",
	       (unsigned long) ehdr->e_entry);
}

/**
 * main - display information contained in ELF file header
 * @argc: number of arguments
 * @argv: array of string arguments
 *
 * Return: EXIT_SUCCESS on success, otherwise 98 on error
 */
int main(int argc, char *argv[])
{
	int descriptor;
	ssize_t r;
	Elf64_Ehdr *helf;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <elf_file>\n", argv[0]);
		exit(98);
	}
	descriptor = open(argv[1], O_RDONLY);
	if (descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: could not open %s\n", argv[1]);
		exit(98);
	}
	helf = malloc(sizeof(Elf64_Ehdr));
	if (helf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: out of memory\n");
		close(descriptor);
		exit(98);
	}
	r = read(descriptor, helf, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(helf);
		dprintf(STDERR_FILENO, "Error: could not read %s\n", argv[1]);
		close(descriptor);
		exit(98);
	}
	if (close(descriptor))
		dprintf(STDERR_FILENO, "Problem closing descriptor %d", descriptor);
	get_magic(helf, argv[1], descriptor);
	get_class(helf);
	get_data(helf);
	get_velf(helf);
	get_osabi(helf);
	get_vabi(helf);
	get_type(helf);
	get_entry(helf);
	free(helf);
	exit(EXIT_SUCCESS);
}
