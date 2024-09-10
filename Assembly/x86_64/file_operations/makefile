fileio:	fileio.o
	gcc -o fileio fileio.o -no-pie
fileio.o: fileio.asm
	nasm -f elf64 -F dwarf -g -o fileio.o fileio.asm -l fileio.lst