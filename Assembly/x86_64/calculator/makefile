calculator:calculator.o
	gcc -o calculator calculator.o -no-pie
calculator.o: calculator.asm
	nasm -f elf64 -g -o calculator.o calculator.asm -l calculator.lst
