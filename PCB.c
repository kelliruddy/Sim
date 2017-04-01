#include "PCB.h"

char * get_string_op(char operation)
{

   switch (operation) {
      case 'S':
         return "system";
      break;

      case 'A':
         return "application";
      break;

      case 'P':
         return "process";
      break;

      case 'M':
         return "memory";
      break;

      case 'I':
         return "input";
      break;

      case 'O':
         return "output";
      break;

      default:
      break;
   }
 return "0";
}


struct PCBNode* nextNode(struct PCBNode* current)
{
   struct PCBNode* newNode = malloc(sizeof(struct PCBNode));

   newNode->next = NULL;
   current->next = newNode;
   return newNode;
}

struct PCBNode* createPCBList(struct Node *metaNode, struct configStruct *configData)
{
   struct PCBNode* startPCB = malloc(sizeof(struct PCBNode));
   struct PCBNode* currentPCB = startPCB;

   int process_count;
   process_count = 0;
   int totalCycles;
   totalCycles = 0;

   while(metaNode->nextNode != NULL)
			{
      int instruction_time;
		    instruction_time = 0;
					 instruction_time = metaNode->cycleTime;

		    char *operation;
		    operation = 0;
		    operation = get_string_op(metaNode->componentLetter);

		    char *descriptor;
		    descriptor = 0;
		    descriptor = metaNode->oprationString;


      if(strcmp(operation, "application") == 0 && strcmp(descriptor, "start") == 0)
      {
          currentPCB->process_count = process_count;
          currentPCB->metaStart = metaNode;
          currentPCB->state = _READY;
      }
      if(strcmp(operation, "application") == 0 && strcmp(descriptor, "end") == 0)
						{
         currentPCB->totalCycles = totalCycles;
         currentPCB = nextNode(currentPCB);
         totalCycles = 0;
         process_count += 1;
						}

     metaNode = metaNode->nextNode;

//------------------Computing Total Number of Cycles for Each Process------------------------------

     if(strcmp(operation, "process") == 0 )
					{
        totalCycles += (instruction_time * configData->processorCycleTimeData)*1000;
        currentPCB->totalCycles = totalCycles;

					}
     if(strcmp(operation, "input") == 0 || strcmp(operation, "output") == 0 )
					{
	       totalCycles += (instruction_time * configData->ioCycleTimeData)*1000;
        currentPCB->totalCycles = totalCycles;
					}
     if(strcmp(operation, "memory") == 0)
				{
       //TODO implement this is in the approprate phase
       totalCycles += 0;
				}//end if(memory)

			}//end while-loop

   return startPCB;
}
