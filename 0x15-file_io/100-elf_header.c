#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

int main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <ELF-file>\n", argv[0]);
		return 1;
	}

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		perror("Error opening file");
		return 1;
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		perror("Error allocating memory");
		close_elf(o);
		return 1;
	}

	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		perror("Error reading file");
		free(header);
		close_elf(o);
		return 1;
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return 0;
}
