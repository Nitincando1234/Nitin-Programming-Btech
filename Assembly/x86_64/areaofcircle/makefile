area:area.o
	gcc -o area area.o -no-pie
area.o: area.asm
	nasm -f elf64 -g -o area.o area.asm -l area.lst
