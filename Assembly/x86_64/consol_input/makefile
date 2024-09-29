consol: consol.o
	gcc -o consol consol.o -no-pie
consol.o: consol.asm
	nasm -f elf64 -F dwarf -g -o consol.o consol.asm -l consol.lst 