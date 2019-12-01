#include "Asmparser.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int currentIdx = 0;
char *text;
char error_mssg[256];
Mnemonic currentMeme;
unsigned int line = 0;
unsigned int column = 0;
Instruction *instructon_list;
size_t length_of_instruction = 0;
Instruction curr_inst = {
    .size = 1,
    .operand_length = 0};

int initParser()
{
    instructon_list = malloc(100 * sizeof(Instruction));
    curr_inst.array_of_operands = malloc(8 * sizeof(Operand));
}
int cleanParser()
{
    free(instructon_list);
    free(curr_inst.array_of_operands);
}
int parse(const char *assemby_text, unsigned int length, char *error_message)
{
    text = assemby_text;
    while (currentIdx < length)
    {
        MainLoop();
    }
}

int encoder(){
    // academic purposes.
}

int decoder() {
    for (size_t i = 0; i < length_of_instruction; i++)
    {
        Instruction order = instructon_list[i];
        switch (order.mnemonic)
        {
        case add:
            
            break;
        
        default:
            break;
        }
    }
    
}

int get_Token()
{
    Mnemonic returnType;
    while (1)
    {
        char asm_mnemonic[8] = "";
        char currChar = getChar();
        if (ispunct(currChar))
        {
            if (currChar == ",")
            {
                returnType = separator;
                break;
            }

            if (currChar == "#")
            {
                returnType = immediate;
                break;
            }

            if (currChar == "@")
            {
                returnType = register_direct;
                break;
            }
        }
        if (isalpha(currChar))
        {
            while (isalpha(currChar))
            {
                strcat(asm_mnemonic, currChar);
                currChar = getChar();
            }

            if (asm_mnemonic == "R")
            {
                returnType = _register;
            }
            if (asm_mnemonic == "A")
            {
                returnType = accumulator;
                break;
            }

            if (asm_mnemonic == "DPTR")
            {
                returnType = data_pointer;
                break;
            }
            if (asm_mnemonic == "ACALL")
            {
                returnType = acall;
                break;
            }

            if (asm_mnemonic == "ADD")
            {
                returnType = add;
                break;
            }

            if (asm_mnemonic == "ADDC")
            {
                returnType = addc;
                break;
            }

            if (asm_mnemonic == "AJMP")
            {
                returnType = ajmp;
                break;
            }

            if (asm_mnemonic == "ANL")
            {
                returnType = anl;
                break;
            }

            if (asm_mnemonic == "CJNE")
            {
                returnType = cjne;
                break;
            }

            if (asm_mnemonic == "CLR")
            {
                returnType = clr;
                break;
            }

            if (asm_mnemonic == "CPL")
            {
                returnType = cpl;
                break;
            }

            if (asm_mnemonic == "DA")
            {
                returnType = da;
                break;
            }

            if (asm_mnemonic == "DEC")
            {
                returnType = dec;
                break;
            }

            if (asm_mnemonic == "DIV")
            {
                returnType = div;
                break;
            }

            if (asm_mnemonic == "DJNZ")
            {
                returnType = djnz;
                break;
            }

            if (asm_mnemonic == "INC")
            {
                returnType = inc;
                break;
            }

            if (asm_mnemonic == "JB")
            {
                returnType = jb;
                break;
            }

            if (asm_mnemonic == "JBC")
            {
                returnType = jbc;
                break;
            }

            if (asm_mnemonic == "JC")
            {
                returnType = jc;
                break;
            }

            if (asm_mnemonic == "JMP")
            {
                returnType = jmp;
                break;
            }

            if (asm_mnemonic == "JNB")
            {
                returnType = jnb;
                break;
            }

            if (asm_mnemonic == "JNC")
            {
                returnType = jnc;
                break;
            }

            if (asm_mnemonic == "JNZ")
            {
                returnType = jnz;
                break;
            }

            if (asm_mnemonic == "JZ")
            {
                returnType = jz;
                break;
            }

            if (asm_mnemonic == "LCALL")
            {
                returnType = lcall;
                break;
            }

            if (asm_mnemonic == "LJMP")
            {
                returnType = ljmp;
                break;
            }

            if (asm_mnemonic == "MOV")
            {
                returnType = mov;
                break;
            }

            if (asm_mnemonic == "MOVC")
            {
                returnType = movc;
                break;
            }

            if (asm_mnemonic == "MOVX")
            {
                returnType = movx;
                break;
            }

            if (asm_mnemonic == "MUL")
            {
                returnType = mul;
                break;
            }

            if (asm_mnemonic == "NOP")
            {
                returnType = nop;
                break;
            }

            if (asm_mnemonic == "ORL")
            {
                returnType = orl;
                break;
            }

            if (asm_mnemonic == "POP")
            {
                returnType = pop;
                break;
            }

            if (asm_mnemonic == "PUSH")
            {
                returnType = push;
                break;
            }

            if (asm_mnemonic == "RET")
            {
                returnType = ret;
                break;
            }

            if (asm_mnemonic == "RETI")
            {
                returnType = reti;
                break;
            }

            if (asm_mnemonic == "RL")
            {
                returnType = rl;
                break;
            }

            if (asm_mnemonic == "RLC")
            {
                returnType = rlc;
                break;
            }

            if (asm_mnemonic == "RR")
            {
                returnType = rr;
                break;
            }

            if (asm_mnemonic == "RRC")
            {
                returnType = rrc;
                break;
            }

            if (asm_mnemonic == "SETB")
            {
                returnType = setb;
                break;
            }

            if (asm_mnemonic == "SJMP")
            {
                returnType = sjmp;
                break;
            }

            if (asm_mnemonic == "SUBB")
            {
                returnType = subb;
                break;
            }

            if (asm_mnemonic == "SWAP")
            {
                returnType = swap;
                break;
            }

            if (asm_mnemonic == "XCH")
            {
                returnType = xch;
                break;
            }

            if (asm_mnemonic == "XCHD")
            {
                returnType = xchd;
                break;
            }

            if (asm_mnemonic == "XRL")
            {
                returnType = xrl;
                break;
            }
        }

        if (isdigit(currChar))
        {
            returnType = number;
            break;
        }

        if (currChar == '\n')
        {
            line++;
            column = 0;
        }
    }
    return returnType;
}

int MainLoop()
{
    currentMeme = get_Token();
    switch (currentMeme)
    {
    case add:
        HandleArithmetic(add);
        Reset();
        break;
    case addc:
        HandleArithmetic(addc);
        Reset();
        break;
    case subb:
        HandleArithmetic(subb);
        Reset();
        break;
    case inc:
        HandleArithmetic(inc);
        Reset();
        break;
    case dec:
        HandleArithmetic(currentMeme);
        Reset();
        break;
    case mul:
        HandleArithmetic(currentMeme);
        Reset();
        break;
    case _div:
        HandleArithmetic(currentMeme);
        Reset();
        break;
    case da:
        HandleArithmetic(currentMeme);
        Reset();
        break;
    case accumulator:
        break;
    case immediate:
        HandleImmediate();
        Reset();
        break;
    default:
        break;
    }
}

int HandleArithmetic(int mnemonic)
{
    switch (mnemonic)
    {
    case subb:
    case addc:
    case add:
        int tok = get_Token();
        if (tok == accumulator)
        {
            tok = get_Token();
            if (tok == separator)
            {
                tok = get_Token();
                curr_inst.mnemonic = mnemonic;
                if (tok == immediate)
                {
                    if (HandleImmediate() == 0)
                    {
                    }
                }
                if (tok == number)
                {
                    if (HandleDirect() == 0)
                    {
                    }
                }

                if (tok == _register)
                {
                    if (HandleRegister() == 0)
                    {
                    }
                }

                if (tok == register_direct)
                {
                    if (HandleRegisterDirect() == 0)
                    {
                    }
                }
            }
        }
        /* code */
        break;

    case dec:
    case inc:
        curr_inst.mnemonic = mnemonic;
        int tok = get_Token();
        switch (tok)
        {
        case accumulator:
            Operand op;
            op.type = A;
            curr_inst.array_of_operands[curr_inst.operand_length++] = op;
            /* code */
            break;
        case _register:
            HandleRegister();
            break;
        case direct:
            HandleDirect();
            break;
        case register_direct:
            HandleRegisterDirect();
            break;
        case data_pointer:
            Operand op;
            op.type = data_pointer_register;
            curr_inst.array_of_operands[curr_inst.operand_length++] = op;
            break;
        default:
            // Do Error
            break;
        }
    case _div:
    case mul:
        curr_inst.mnemonic = mul;
        int tok = get_Token();
        if (tok == accumulator)
        {
            Operand op;
            op.type = A;
            curr_inst.array_of_operands[curr_inst.operand_length++] = op;
            tok = get_Token();
            if (tok == bccumulator)
            {
                Operand op;
                op.type = B;
                curr_inst.array_of_operands[curr_inst.operand_length++] = op;
            }
        }
    case da:
        int tok = get_Token();
        if (tok == accumulator)
        {
            curr_inst.mnemonic = da;
            Operand op;
            op.type = A;
            curr_inst.array_of_operands[curr_inst.operand_length++] = op;
        }
    default:
        // Do Error
        break;
    }
}

int HandleRegisterDirect()
{
    int tok = get_Token();
    if (tok == _register)
    {
        if (HandleRegister() == 0)
        {
            Operand *_operand = &curr_inst.array_of_operands[curr_inst.operand_length - 1];
            _operand->type = _register_address;
        }
    }
}

int HandleRegister()
{
    char c = getChar();
    if (isdigit(c))
    {
        if (isalnum(peek()))
        {
            // say error. register cannot be more than one digit
            return 1;
        }
        else
        {
            char string[8] = "";
            long value = strtol(string, NULL, 10);
            Operand _operand;
            _operand.type = _register_;
            _operand.value = value;
            curr_inst.array_of_operands[curr_inst.operand_length++] = _operand;
            return 0;
        }
    }
}

int HandleDirect()
{
    size_t n = 0;
    char number_string[16];
    char c;
    strcat(&number_string[n++], getCurrentCharInScope());
    while (isdigit(c = getChar()))
    {
        strcat(&number_string, c);
    }
    number_string[n] = "\0";
    if (c == "h")
    {
        long value = strtol(number_string, NULL, 16);
        Operand _operand;
        _operand.type = _address;
        _operand.value = value;
        curr_inst.array_of_operands[curr_inst.operand_length++] = _operand;
    }
}

int HandleImmediate()
{
    size_t n = 0;
    char number_string[8];
    char c;
    while (isdigit(c = getChar()))
    {
        strcat(&number_string[n++], c);
    }
    number_string[n] = "\0";
    if (isalpha(c))
    {
        if (c = "h")
        {
            int value = strtol(number_string, NULL, 16);
            Operand _operand;
            _operand.type = _immediate;
            _operand.value = value;
            curr_inst.array_of_operands[curr_inst.operand_length++] = _operand;
            curr_inst.size = 2;
            return 0;
        }
    }
}

int Reset()
{
    instructon_list[length_of_instruction++] = curr_inst;
    curr_inst.operand_length = 0;
    curr_inst.size = 1;
}

int HandleJMP()
{
}

int HandleIO()
{
}

int HandleLogic()
{
}
int getChar()
{
    return text[currentIdx++];
}

int getCurrentCharInScope()
{
    return text[currentIdx];
}

int peek()
{
    return text[currentIdx + 1];
}