#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#include "parMethods.h"
#include "PCB.h"


//Pre-Declarations
void fcfsScheduling(struct PCBNode* startPCB, struct configStruct *configData, double startTime);
void sjfScheduling(struct PCBNode* startPCB, struct configStruct *configData, double startTime);

void print_sim(struct PCBNode* startPCB, struct configStruct *configData, double startTime, FILE *file);

void *threadDelay(void *voidPtr);
double time_Difference(double time_start);

#endif
