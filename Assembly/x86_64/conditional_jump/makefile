jump: condjump.o
	gcc -o jump condjump.o -no-pie
condjump.o: condjump.asm
	nasm -f elf64 -g -o condjump.o condjump.asm -l condjump.lst
