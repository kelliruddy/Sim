
#include"mainprog.h"


int main(int argc, char *argv[])
  {
     FILE *fPrt;


     if(argc < 2)
       {
          printf("you did not give enough Command line arguments");
          return 0;
       }
     if(argc > 2)
       {
          printf("you gave to many command line arguments");
          return 0;
       }
     // ADTs for holding data
     struct configStruct configData;
     struct Node *metaDataLinkListNodeFirst  = (struct Node *)malloc (sizeof(struct Node));

     // start of parsing though the config file
     doesFileExist(argv[1]);
     fPrt = fopen(argv[1], "r");
     printf("\n");

     configData = parConfigFile(fPrt);




     fclose(fPrt);
     // end of parsing though the config file

     // start of parsing though the meta data file
     doesFileExist(configData.filePathData);
     fPrt = fopen(configData.filePathData, "r");


//-------------------------Start of Simulation----------------------------------
     metaDataLinkListNodeFirst = parMetaDataFile(fPrt);

     printf("Begin Simulation\n\n");

     struct PCBNode* startPCB = createPCBList(metaDataLinkListNodeFirst, &configData);

     if(strcmp(configData.cpuSchedulingCodeData, "NONE") == 0 || strcmp(configData.cpuSchedulingCodeData, "FCFS-N") == 0)
     {
        fcfsScheduling(startPCB, &configData, 0.0);
     }
     else if(strcmp(configData.cpuSchedulingCodeData, "SJF-N") == 0)
    {
      sjfScheduling(startPCB, &configData, 0.0);
    }
    else
   {
      printf("Pick a proper scheduling code: NONE, FCFS-N, SJF-N \n");
   }

     fclose(fPrt);
     printf("\n");
     // end of parsing though the meta data file
     return 0;


  }

void doesFileExist(char* fileName)
  {
     FILE *fPrt;
     if((fPrt = fopen(fileName, "r")))
       {
          // printf("\nwe are good to go (%s) is a valid file\n",fileName);
          fclose(fPrt);
       }
     else
       {
          printf("The file ( %s ) does not exist.\n", fileName);
          printf("Ending program.\n");
          exit(1);
       }
  }


void printConfigData(struct configStruct *configData)
  {
   printf("\nVersion/Phase: %d",configData->versionData);
   printf("\nFile Path: %s",configData->filePathData);
   printf("\nCPU Scheduling Code: %s",configData->cpuSchedulingCodeData);
   printf("\nQuantum Time: %d",configData->quantumTimeData);
   printf("\nMemory Available (KB): %d",configData->memoryAvailableData);
   printf("\nProcessor Cycle Time (msec): %d",configData->memoryAvailableData);
   printf("\nI/O Cycle Time (msec): %d",configData->ioCycleTimeData);
   printf("\nLog To: %s",configData->logToData);
   printf("\nLog File Path: %s\n",configData->logFilePathData);
  }
