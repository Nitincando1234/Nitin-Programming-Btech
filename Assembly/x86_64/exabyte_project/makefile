exabyte:exabyte.o
	gcc -o exabyte exabyte.o -no-pie
exabyte.o: exabyte.asm
	nasm -f elf64 -g -o exabyte.o exabyte.asm -l exabyte.lst
