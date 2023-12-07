#ifndef SYSTEM_H
#define SYSTEM_H
#include "types.h"
uint8 inportb (uint16 _port);

/*

{
    uint8 rv;
    _asm__volatile_("inb %1, %0" : "=a" (rv) : "dN" (_port));
}

*/

void outportb (uint16 _port, uint8 _data);

/*

{
    uint8 rv;
    _asm__volatile_("outb %1, %0" : : "dN" (_port), "a" (_data));
}

*/

#endif
