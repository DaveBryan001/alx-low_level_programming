#include "main.h"
#include <elf.h>

#define BUF_SIZE 64

/**
 * display_error - Display an error message and exit with status code 98.
 * @message: The error message to display.
 */
void display_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

/**
 * display_elf_header - Display information from the ELF header.
 * @elf_header: Pointer to the ELF header structure.
 */
void display_elf_header(const Elf64_Ehdr *elf_header)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; ++i)
	{
		printf("%02x ", elf_header->e_ident[i]);
	}
	printf("\n");

	printf("  Class:                             %s\n",
			(elf_header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
			(elf_header->e_ident[EI_DATA] == ELFDATA2LSB)
			? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d\n",
			elf_header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %d\n",
			elf_header->e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n",
			elf_header->e_ident[EI_ABIVERSION]);

	printf("  Type:                              %s\n",
			(elf_header->e_type == ET_EXEC) ? "EXEC (Executable file)" :
			(elf_header->e_type == ET_REL) ? "REL (Relocatable file)" :
			(elf_header->e_type == ET_DYN) ? "DYN (Shared object file)" :
			(elf_header->e_type == ET_CORE) ? "CORE (Core file)" : "Unknown");

	printf("  Entry point address:               0x%lx\n",
			(unsigned long)elf_header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{

	Elf64_Ehdr elf_header;
	const char *filename;
	int fd;

	if (argc != 2)
	{
		display_error("Usage: elf_header elf_filename");
	}

	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		display_error("Error opening file");
	}

	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		display_error("Error reading ELF header");
	}

	if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		display_error("Not an ELF file");
	}

	display_elf_header(&elf_header);

	close(fd);
	return (0);
}

