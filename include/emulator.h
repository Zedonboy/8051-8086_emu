#include "stdint.h"
#include "malloc.h"
#define NUMBER_OF_BANK 4
typedef struct DPTR{
    uint8_t DPH;
    uint8_t DPL;
} _dptr;

typedef struct PSW
{
    uint8_t cy:1; // Carry Flag
    uint8_t ac:1; // Auxiliary Carry flag (For BCD Operations)
    uint8_t f0:1; // Flag 0 (Available to the user for General Purpose)
    uint8_t rs:2; // Register select
    uint8_t ov:1; // Overflow flag
    uint8_t ud:1; // User Definable

} psw;

typedef struct State8051
{
    uint8_t a;
    uint8_t b;
    uint8_t *memory;
    uint16_t sp;
    uint16_t pc;
    struct PSW _psw;
    struct DPTR _dptr;
} Machine
