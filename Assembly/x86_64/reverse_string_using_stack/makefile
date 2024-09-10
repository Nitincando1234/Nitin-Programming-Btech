stack:stack.o
	gcc -o stack stack.o -no-pie
stack.o: stack.asm
	nasm -f elf64 -g -o stack.o stack.asm -l stack.lst
