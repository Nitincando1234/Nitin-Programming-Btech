console: console.o
	gcc -o console console.o -no-pie
console.o: console.asm
	nasm -f elf64 -F dwarf -g -o console.o console.asm -l console.lst 