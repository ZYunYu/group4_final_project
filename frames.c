#include <stdio.h>
#include <final_proj.h>

void read_from_backing_store(unsigned char* physicalMemory, int frameNumber, const char* backingStoreFile) {
    long position = frameNumber * FRAME_SIZE;

    FILE* backingStore = fopen(backingStoreFile, "rb");
    if (backingStore == NULL) {
        printf("Failed to open backing store file.\n");
        return;
    }

    if (fseek(backingStore, position, SEEK_SET) != 0) {
        printf("Failed to seek in backing store file.\n");
        fclose(backingStore);
        return;
    }

    size_t bytesRead = fread(physicalMemory + (frameNumber * FRAME_SIZE), sizeof(unsigned char), FRAME_SIZE, backingStore);
    if (bytesRead != FRAME_SIZE) {
        printf("Failed to read from backing store file.\n");
        fclose(backingStore);
        return;
    }

    fclose(backingStore);
}
