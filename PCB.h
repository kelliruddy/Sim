#ifndef PCB_H
#define  PCB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parMethods.h"
//#include "processManager.h"

typedef enum
{
    _NEW = 0,
    _READY = 1,
    _RUNNING = 2,
    _EXIT = 3,
} process_states;

//the data structure to represent the PCB
struct PCBNode
{
   process_states state;
   int process_count;
   int totalCycles;

   struct Node *metaStart;
   struct PCBNode *next;
};

//Pre-Declarations
char * get_string_op(char operation);
struct PCBNode* nextNode(struct PCBNode* current);
struct PCBNode* createPCBList(struct Node *metaNode, struct configStruct *configData);

#endif
