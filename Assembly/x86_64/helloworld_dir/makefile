#Makefile for hello.asm
helloworld: helloworld.o
	gcc -o helloworld helloworld.o -no-pie
helloworld.o: helloworld.asm
	nasm -f elf64 -g -F dwarf helloworld.asm -l helloworld.lst
