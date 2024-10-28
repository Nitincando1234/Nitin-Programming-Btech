registers:registers.o
	gcc -o registers registers.o -no-pie
registers.o: registers.asm
	nasm -f elf64 -g -o registers.o registers.asm -l registers.lst
