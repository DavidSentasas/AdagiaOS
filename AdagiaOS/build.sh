nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -c kernel.c -o kc.o -ffreestanding
gcc -m32 -c include/system.c -o obj/system.o -ffreestanding # careful, empty ang obj folder
gcc -m32 -c include/string.c -o obj/string.o -ffreestanding
gcc -m32 -c include/screen.c -o obj/screen.o -ffreestanding
gcc -m32 -c include/kb.c -o obj/system.o -ffreestanding
ld -m elf_i386 -T link.ld -o kernelboot/boot/kernel.bin kasm.o kc.o obj/system.o obj/string.o  obj/screen.o obj/kb.o


qemu -kernel kernelboot/boot/kernel.bin
#grub -mkrescue -o adagia.iso adagia/

read a
# make sure this is executable (right click on file)