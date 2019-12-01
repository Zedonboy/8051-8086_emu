#include <stdint.h>
typedef enum InstrunctionGroup{arithmetic, branch, logical, io} InstrunctionGroup;
typedef enum Mnemonic{acall, add, addc, ajmp, anl, cjne, clr, cpl, da, dec, _div, djnz, inc, jb, jbc, jc, jmp, jnb, jnc, jnz, jz, lcall, ljmp, mov, movc, movx, mul, nop, orl, pop, push, ret, reti, rl, rlc, rr, rrc, setb, sjmp, subb, swap, xch, xchd, xrl, accumulator,bccumulator, direct, immediate, addr11, addr16, bit, _register, register_direct, separator, number, data_pointer} Mnemonic;
typedef enum OperandType{_register_, _immediate, _address, _register_address, A, B, C, data_pointer_register} OperandType;
typedef struct Operand
{
    OperandType type;
    uint16_t value;
} Operand;

typedef struct Instruction{
    InstrunctionGroup group;
    Mnemonic mnemonic;
    uint8_t operand_length;
    Operand *array_of_operands;
    size_t size;
} Instruction;
