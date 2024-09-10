move:move.o
	gcc -o move move.o -no-pie
move.o: move.asm
	nasm -f elf64 -g -o move.o move.asm -l move.lst
