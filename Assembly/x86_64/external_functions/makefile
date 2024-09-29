mainfunction:mainfunction.o circle.o rectangle.o
	gcc -o mainfunction mainfunction.o circle.o rectangle.o -no-pie
mainfunction.o: mainfunction.asm
	nasm -f elf64 -g -F dwarf mainfunction.asm -l mainfunction.lst
circle.o: circle.asm
	nasm -f elf64 -g -F dwarf circle.asm -l circle.lst
rectangle.o: rectangle.asm
	nasm -f elf64 -g -F dwarf rectangle.asm -l rectangle.lst