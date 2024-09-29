macro: macro.o
	gcc -o macro macro.o -no-pie
macro.o: macro.asm
	nasm -f elf64 -F dwarf -g -o macro.o macro.asm -l macro.lst