#ifndef CPU_H
#define CPU_H

#include "instruction.h"
#include "memory.h"

typedef struct {
    Instruction* instructions;
    HD hd;
    RAM ram;
    Cache l1; 
    Cache l2; 
    Cache l3; 
    int hitL1, hitL2, hitL3, hitRAM, hitHD;
    int missL1, missL2, missL3, missRAM;
    int totalCost;
    int NumInstructions;
} Machine;

void start(Machine*, Instruction*, int*);
void stop(Machine*);
void run(Machine*);
void printMemories(Machine*);

#endif // !CPU_H