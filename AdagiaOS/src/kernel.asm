bits    32
section         .text
        align   4
        dd      0x1BADB002 ; bootloader location
        dd      0x00
        dd      - (0x1BADB002+0x00)
        
global start
extern kmain            ; in kernel.c
start:
        cli             ; stops interrupts 
        call kmain      ; continue execution, function located in c
        hlt             ; halts cpu

