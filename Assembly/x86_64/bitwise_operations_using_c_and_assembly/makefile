bit: bit.o printb.o
	gcc -g -o bit bit.o printb.o -no-pie
bit.o: bit.asm
	nasm -f elf64 -g -F dwarf bit.asm -l bit.lst
printb.o: printb.c
	gcc -c -o printb.o printb.c
