#include <stdio.h>
#include "final_proj.h"
#include <stdlib.h>
signed char* physicalMemory;
signed char*  read_from_backing_store(int frameNumber, const char* backingStoreFile) {
    long position = frameNumber * FRAME_SIZE;
    physicalMemory = (signed char*) malloc(sizeof(signed char)*VIRTUAL_MEMORY_SIZE);
    


    FILE* backingStore = fopen(backingStoreFile, "rb");
    if (backingStore == NULL) {
        printf("Failed to open backing store file.\n");
        exit(1);
    }
    

    if (fseek(backingStore, position, SEEK_SET) != 0) {
        printf("Failed to seek in backing store file.\n");
        fclose(backingStore);
        exit(1);
    }
    

    size_t bytesRead = fread(&physicalMemory[position], sizeof(signed char), FRAME_SIZE, backingStore);
   
    if (bytesRead != FRAME_SIZE) {
        printf("Failed to read from backing store file.\n");
        fclose(backingStore);
        exit(1);
    }
    

    fclose(backingStore);
    return physicalMemory;
}





