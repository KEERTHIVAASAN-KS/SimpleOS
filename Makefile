create:
	mkdir build
	nasm -f elf32 source/kernel.asm -o build/kern1.o
	gcc -m32 -c -nostdlib -ffreestanding source/kernel.c -o build/kern2.o
	ld -T link.ld -m elf_i386 -o build/kernel.bin build/kern1.o build/kern2.o
	qemu-system-i386 -kernel build/kernel.bin
remove:
	rm build/kernel.bin build/kern1.o build/kern2.o
        rmdir build
	
	
	
