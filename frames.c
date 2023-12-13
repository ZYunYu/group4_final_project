#include <stdio.h>
#include "final_proj.h"
#include <stdlib.h>
signed char* frames;
void read_from_backing_store(signed char* physicalMemory, int frameNumber, const char* backingStoreFile) {
    long position = frameNumber * FRAME_SIZE;
    frames = (signed char*) malloc(sizeof(signed char)*VIRTUAL_MEMORY_SIZE);
    


    FILE* backingStore = fopen(backingStoreFile, "rb");
    if (backingStore == NULL) {
        printf("Failed to open backing store file.\n");
        return;
    }
    printf("before seek \n");

    if (fseek(backingStore, position, SEEK_SET) != 0) {
        printf("Failed to seek in backing store file.\n");
        fclose(backingStore);
        return;
    }
    printf("after seek \n");

    size_t bytesRead = fread(physicalMemory[position], sizeof(signed char), FRAME_SIZE, backingStore);
   
    if (bytesRead != FRAME_SIZE) {
        printf("Failed to read from backing store file.\n");
        fclose(backingStore);
        return;
    }
    printf("after bytes read");

    fclose(backingStore);
}

int main(int argc, char const *argv[])
{
   read_from_backing_store(frames,0,argv[1]);

    
}




