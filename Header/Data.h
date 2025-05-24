#ifndef DATA_H
#define DATA_H

#include "Table.h"

/*
Global Data in the program
Data like length of a label and a single command line, IC value 
BITS, OPcode, Registry, A.R.E.
*/


#define MAX_LABEL_LENGTH 31 
#define MAX_LINE_LENGTH 81
#define IC_VALUE 100
#define BIG_NUMBER 1000
#define OPCODES_COUNT 16
#define REGISTRY_COUNT 8
#define BINARY_LEN 12
#define ARE_BITS 2
#define RELOCATABLE_VALUE 2
#define EXTERNAL_VALUE 1
#define INSTRUCTIONS_COUNT 4
#define MAX_NUM ((1 << (WORD_LEN-1)) - 1)
#define MIN_NUM (-(1 << (WORD_LEN-1)))

/*
#define SIX_BITS_MAX 63 
#define SIX_BITS 6 
#define NUM_SEXTETES 2 
*/

/*
Define the opcodes 
op_code OPCODES[] = 
{
    {"mov",  2},
    {"cmp",  2},
    {"add",  2},
    {"sub",  2},
    {"not",  1},
    {"clr",  1},
    {"lea",  2},
    {"inc",  1},
    {"dec",  1},
    {"jmp",  1},
    {"bne",  1},
    {"red",  1},
    {"prn",  1},
    {"jsr",  1},
    {"rts",  0},
    {"hlt", 0}
};

extern op_code OPCODES[];

Define the registers 
char *REGS[] = {"@r0", "@r1", "@r2", "@r3", "@r4", "@r5", "@r6", "@r7"};

extern char *REGS[];


 Define the instructions 
char *INSTUCTIONS[] = {".data", ".string", ".extern", ".entry"};

extern char *INSTRUCTIONS[];
*/

#endif 









