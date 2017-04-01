#include "scheduler.h"

void fcfsScheduling(struct PCBNode* startPCB, struct configStruct *configData, double startTime)
{
    double totalTime;
    totalTime = 0;

   FILE *file;
   file = fopen(configData->logFilePathData, "w");

   if(strcmp(configData->logToData, "Monitor") == 0 || strcmp(configData->logToData, "monitor") == 0)
   {
      printf("Printing to MONITOR");

      printf("Time: %lf, System start \n", totalTime);

      totalTime = time_Difference(startTime);
      printf("Time: %lf, OS: Begin PCB Creation \n", totalTime);

      totalTime = time_Difference(startTime);
      printf("Time: %lf, OS: All processes initialized to new state \n", totalTime);

      //loop through the linked list of PCB's

      struct PCBNode* currentPCB = startPCB;
      while(currentPCB->next != NULL)
   			{
         totalTime = time_Difference(startTime);
         printf("\n\n\nTime: %lf, OS: FCFS Scheduling. \n\tProcess %d will take approximately %d us\n\n",
                totalTime, currentPCB->process_count, (currentPCB->totalCycles)/10000);

         print_sim(currentPCB, configData, startTime, file);

         currentPCB = currentPCB->next;
   			}
         totalTime = time_Difference(startTime);
         printf("Time %lf, System stop\n", totalTime);
   }
   else if(strcmp(configData->logToData, "File") == 0 || strcmp(configData->logToData, "file") == 0)
   {
        double totalTime;
        totalTime = 0;

        fprintf(file, "Time: %lf, System start \n", totalTime);

        totalTime = time_Difference(startTime);
        fprintf(file, "Time: %lf, OS: Begin PCB Creation \n", totalTime);

        totalTime = time_Difference(startTime);
        fprintf(file, "Time: %lf, OS: All processes initialized to new state \n", totalTime);

        //loop through the linked list of PCB's
        struct PCBNode* currentPCB = startPCB;
        while(currentPCB->next != NULL)
     			{
           totalTime = time_Difference(startTime);
           fprintf(file, "\n\n\nTime: %lf, OS: FCFS Scheduling. \n\tProcess %d will take approximately %d us\n\n",
                  totalTime, currentPCB->process_count, (currentPCB->totalCycles)/1000);

           print_sim(currentPCB, configData, startTime, file);

           currentPCB = currentPCB->next;
     			}
           totalTime = time_Difference(startTime);
           fprintf(file, "Time %lf, System stop\n", totalTime);
   }
   else if(strcmp(configData->logToData, "both") == 0 || strcmp(configData->logToData, "Both") == 0)
   {
      double totalTime;
      totalTime = 0;

      printf("Time: %lf, System start \n", totalTime);
      fprintf(file, "Time: %lf, System start \n", totalTime);

      totalTime = time_Difference(startTime);
      printf("Time: %lf, OS: Begin PCB Creation \n", totalTime);
      fprintf(file, "Time: %lf, OS: Begin PCB Creation \n", totalTime);

      totalTime = time_Difference(startTime);
      printf("Time: %lf, OS: All processes initialized to new state \n", totalTime);
      fprintf(file, "Time: %lf, OS: All processes initialized to new state \n", totalTime);

      //loop through the linked list of PCB's

      struct PCBNode* currentPCB = startPCB;
      while(currentPCB->next != NULL)
   			{
         totalTime = time_Difference(startTime);
         printf("\n\n\nTime: %lf, OS: FCFS Scheduling. \n\tProcess %d will take approximately %d us\n\n",
                totalTime, currentPCB->process_count, (currentPCB->totalCycles)/1000);
         fprintf(file, "\n\n\nTime: %lf, OS: FCFS Scheduling. \n\tProcess %d will take approximately %d us\n\n",
                totalTime, currentPCB->process_count, (currentPCB->totalCycles)/1000);

         print_sim(currentPCB, configData, startTime, file);

         currentPCB = currentPCB->next;
   			}
         totalTime = time_Difference(startTime);
         printf("Time %lf, System stop\n", totalTime);
         fprintf(file, "Time %lf, System stop\n", totalTime);
   }
   else
   {
      printf("Could not find where to log the information to \n");
   }

   fclose(file);
}


void sjfScheduling(struct PCBNode* startPCB, struct configStruct *configData, double startTime)
{
   double totalTime;
   totalTime = 0;

   FILE *file;
   file = fopen(configData->logFilePathData, "w");

   if(strcmp(configData->logToData, "Monitor") == 0 || strcmp(configData->logToData, "monitor") == 0)
   {
      printf("Time: %lf, System start\n", totalTime);

      totalTime = time_Difference(startTime);
      printf("Time: %lf, OS: Begin PCB Creation\n", totalTime);

      totalTime = time_Difference(startTime);
      printf("Time: %lf, OS: All processes are initialized to new state\n", totalTime);
   }
   else if(strcmp(configData->logToData, "File") == 0 || strcmp(configData->logToData, "file") == 0)
   {
      fprintf(file, "Time: %lf, System start\n", totalTime);

      totalTime = time_Difference(startTime);
      fprintf(file, "Time: %lf, OS: Begin PCB Creation\n", totalTime);

      totalTime = time_Difference(startTime);
      fprintf(file, "Time: %lf, OS: All processes are initialized to new state\n", totalTime);
   }
   else if(strcmp(configData->logToData, "both") == 0 || strcmp(configData->logToData, "Both") == 0)
   {
      printf("Time: %lf, System start\n", totalTime);
      fprintf(file, "Time: %lf, System start\n", totalTime);

      totalTime = time_Difference(startTime);
      printf("Time: %lf, OS: Begin PCB Creation\n", totalTime);
      fprintf(file, "Time: %lf, OS: Begin PCB Creation\n", totalTime);

      totalTime = time_Difference(startTime);
      printf("Time: %lf, OS: All processes are initialized to new state\n", totalTime);
      fprintf(file, "Time: %lf, OS: All processes are initialized to new state\n", totalTime);

   }
   else
   {
      printf("Could not find where to log the information to \n");
   }

    //struct PCBNode* lastPCBNode;
    struct PCBNode* lastPCB = startPCB;
    int numProcesses = 0;

    while(lastPCB->next != NULL)
    {
      //lastPCBNode = lastPCB;
      lastPCB = lastPCB->next;
      ++numProcesses;
    }

    int counter;
    struct PCBNode* tempNode = startPCB;
    int buffer[200];

    for(counter = 0; counter < numProcesses+1; counter++)
    {
      buffer[counter] = tempNode->totalCycles;
      tempNode = tempNode->next;
    }

    int out;
    int in;
    int min;
    int temp;


    for(out = 0; out < numProcesses+1; out++)
    {
      min = out;
      for(in = out+1; in < numProcesses; in++)
      {
         if(buffer[in] < buffer[min])
         {
            min = in;
         }
      }
         temp = buffer[min];
         buffer[min] = buffer[out];
         buffer[out] = temp;
   }

   struct PCBNode* currentPCB = startPCB;
   int count = 0;

   //printing in SJF order
   while(currentPCB->next != NULL)
			{
      if(buffer[count] == currentPCB->totalCycles)
						{
         if(strcmp(configData->logToData, "Monitor") == 0 || strcmp(configData->logToData, "monitor") == 0)
         {
     		      totalTime = time_Difference(startTime);
     		      printf("\n\n\nTime: %lf, OS: SJF Scheduling. \n\tProcess %d will take approximately %d us\n\n",
     		             totalTime, currentPCB->process_count, (currentPCB->totalCycles)/1000);

             print_sim(currentPCB, configData, startTime, file);
         }
         else if(strcmp(configData->logToData, "File") == 0 || strcmp(configData->logToData, "file") == 0)
         {
     		      totalTime = time_Difference(startTime);
     		      fprintf(file, "\n\n\nTime: %lf, OS: SJF Scheduling. \n\tProcess %d will take approximately %d us\n\n",
     		             totalTime, currentPCB->process_count, (currentPCB->totalCycles)/1000);

             print_sim(currentPCB, configData, startTime, file);
         }
         else if(strcmp(configData->logToData, "both") == 0 || strcmp(configData->logToData, "Both") == 0)
         {
     		      totalTime = time_Difference(startTime);
     		      printf("\n\n\nTime: %lf, OS: SJF Scheduling. \n\tProcess %d will take approximately %d us\n\n",
     		             totalTime, currentPCB->process_count, (currentPCB->totalCycles)/1000);
     		      fprintf(file, "\n\n\nTime: %lf, OS: SJF Scheduling. \n\tProcess %d will take approximately %d us\n\n",
     		             totalTime, currentPCB->process_count, (currentPCB->totalCycles)/1000);

             print_sim(currentPCB, configData, startTime, file);
         }
         else
         {
            printf("Could not find where to log the information to \n");
         }

        currentPCB = startPCB;
        count++;
						}
      else
						{
         currentPCB = currentPCB->next;
						}
			}
}

void print_sim(struct PCBNode* startPCB, struct configStruct *configData, double startTime, FILE *file)
{
   pthread_t thread;
   int iret;

   double totalTime;
   totalTime = 0;

   struct Node* metaCurrent;
   metaCurrent = startPCB->metaStart;

   while(metaCurrent->nextNode != NULL)
			{
      double cycleTime, delayTime;
      cycleTime = 0;
      delayTime = 0;

      //getting instruction data
			   double instruction_time;
      instruction_time = 0;
			   instruction_time = metaCurrent->cycleTime;

      char *operation;
      operation = 0;
      operation = get_string_op(metaCurrent->componentLetter);

      char *descriptor;
      descriptor = 0;
      descriptor = metaCurrent->oprationString;


      if(strcmp(configData->logToData, "Monitor") == 0 || strcmp(configData->logToData, "monitor") == 0)
      {
         if(strcmp(operation, "application") == 0 && strcmp(descriptor, "start") == 0)
   						{
            totalTime = time_Difference(startTime);
            printf("Time: %lf, OS: Process %d set in Running state.\n", totalTime, startPCB->process_count);
   						}
         else if(strcmp(operation, "application") == 0 && strcmp(descriptor, "end") == 0)
    					{
            break;
    					}
         else if(strcmp(operation, "input") == 0 || strcmp(operation, "output") == 0 || strcmp(operation, "process") == 0)
    					{
            if(strcmp(operation, "process") == 0)
    								{
               cycleTime = configData->processorCycleTimeData;
    								}
            else
    								{
               cycleTime = configData->ioCycleTimeData;
    								}

            totalTime = time_Difference(startTime);
            printf("Time: %lf, Process %d, %s %s start\n", totalTime, startPCB->process_count, descriptor, operation);

            delayTime = (cycleTime * instruction_time)/1000;
            iret = pthread_create(&thread, NULL, threadDelay, &delayTime);
            if(iret)
            {
               fprintf(stderr, "Error: pthread_create() return code: %d\n", iret);
               exit(EXIT_FAILURE);
            }
            pthread_join(thread, NULL);

            totalTime = time_Difference(startTime);
    				    printf("Time: %lf, Process %d, %s %s end\n", totalTime, startPCB->process_count, descriptor, operation);
    					}
         else if(strcmp(operation, "memory") == 0)
         {
            totalTime = time_Difference(startTime);
            printf("Time: %lf, Process %d, Memory management %s action \n", totalTime, startPCB->process_count, descriptor);
         }
          metaCurrent = metaCurrent->nextNode;

      }

      else if(strcmp(configData->logToData, "File") == 0 || strcmp(configData->logToData, "file") == 0)
      {
         if(strcmp(operation, "application") == 0 && strcmp(descriptor, "start") == 0)
   						{
            totalTime = time_Difference(startTime);
            fprintf(file, "Time: %lf, OS: Process %d set in Running state.\n", totalTime, startPCB->process_count);
   						}
         else if(strcmp(operation, "application") == 0 && strcmp(descriptor, "end") == 0)
    					{
            break;
    					}
         else if(strcmp(operation, "input") == 0 || strcmp(operation, "output") == 0 || strcmp(operation, "process") == 0)
    					{
            if(strcmp(operation, "process") == 0)
    								{
               cycleTime = configData->processorCycleTimeData;
    								}
            else
    								{
               cycleTime = configData->ioCycleTimeData;
    						  }

            totalTime = time_Difference(startTime);
            fprintf(file, "Time: %lf, Process %d, %s %s start\n", totalTime, startPCB->process_count, descriptor, operation);

            delayTime = (cycleTime * instruction_time)/1000;
            iret = pthread_create(&thread, NULL, threadDelay, &delayTime);
            if(iret)
            {
               fprintf(stderr, "Error: pthread_create() return code: %d\n", iret);
               exit(EXIT_FAILURE);
            }
            pthread_join(thread, NULL);

            totalTime = time_Difference(startTime);
    				    fprintf(file, "Time: %lf, Process %d, %s %s end\n", totalTime, startPCB->process_count, descriptor, operation);
    					}
         else if(strcmp(operation, "memory") == 0)
         {
            totalTime = time_Difference(startTime);
            fprintf(file, "Time: %lf, Process %d, Memory management %s action \n", totalTime, startPCB->process_count, descriptor);
         }
          metaCurrent = metaCurrent->nextNode;
      }

      else if(strcmp(configData->logToData, "both") == 0 || strcmp(configData->logToData, "Both") == 0)
      {
         if(strcmp(operation, "application") == 0 && strcmp(descriptor, "start") == 0)
         {
            totalTime = time_Difference(startTime);
            printf("Time: %lf, OS: Process %d set in Running state.\n", totalTime, startPCB->process_count);
            fprintf(file, "Time: %lf, OS: Process %d set in Running state.\n", totalTime, startPCB->process_count);
         }
         else if(strcmp(operation, "application") == 0 && strcmp(descriptor, "end") == 0)
         {
            break;
         }
         else if(strcmp(operation, "input") == 0 || strcmp(operation, "output") == 0 || strcmp(operation, "process") == 0)
         {
           if(strcmp(operation, "process") == 0)
           {
              cycleTime = configData->processorCycleTimeData;
           }
           else
           {
              cycleTime = configData->ioCycleTimeData;
           }

           totalTime = time_Difference(startTime);
           printf("Time: %lf, Process %d, %s %s start\n", totalTime, startPCB->process_count, descriptor, operation);
           fprintf(file, "Time: %lf, Process %d, %s %s start\n", totalTime, startPCB->process_count, descriptor, operation);

           delayTime = (cycleTime * instruction_time)/1000000;
           iret = pthread_create(&thread, NULL, threadDelay, &delayTime);
           if(iret)
           {
              fprintf(stderr, "Error: pthread_create() return code: %d\n", iret);
              exit(EXIT_FAILURE);
           }
           pthread_join(thread, NULL);

           totalTime = time_Difference(startTime);
           printf("Time: %lf, Process %d, %s %s end\n", totalTime, startPCB->process_count, descriptor, operation);
           fprintf(file, "Time: %lf, Process %d, %s %s end\n", totalTime, startPCB->process_count, descriptor, operation);
         }
         else if(strcmp(operation, "memory") == 0)
         {
           totalTime = time_Difference(startTime);
           printf("Time: %lf, Process %d, Memory management %s action \n", totalTime, startPCB->process_count, descriptor);
           fprintf(file, "Time: %lf, Process %d, Memory management %s action \n", totalTime, startPCB->process_count, descriptor);
         }
         metaCurrent = metaCurrent->nextNode;
      }
      else
      {
         printf("Could not find where to log the information to \n");
      }

			}
}

/*Waits for the given amount of time in seconds. (Can be be in precision of
  milliseconds).*/
void *threadDelay(void *voidPtr)
{
   double *wait_time = (double *) voidPtr;

   clock_t start_time, total_Time;

   start_time = clock();
   total_Time = (double) (clock() - start_time)/CLOCKS_PER_SEC;

   while(total_Time <= *wait_time)
   {
      total_Time = (double) (clock() - start_time)/CLOCKS_PER_SEC;
   }

   return 0;
}

//gets the current time and returns the difference & time_start is in units of s
double time_Difference(double time_start)
{
   double result;
   result = (clock() - time_start)/CLOCKS_PER_SEC;
   return result;
}





//
