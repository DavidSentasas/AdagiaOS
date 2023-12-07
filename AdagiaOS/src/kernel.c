#include "../include/kb.h"
#include "../include/isr.h"
#include "../include/idt.h"
#include "../include/util.h"
#include "../include/shell.h"
kmain()
{
	isr_install();
	clearScreen();
	print("ADAGIA OS \nPlease enter a command. Enter help for list of commands.\n");
    launch_shell(0);    
}

