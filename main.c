#include <stdio.h>
#include <stdlib.h>

int* read_addresses(char* filename) {
    printf("Before open ");
    FILE* fp  = fopen(filename,"r");
    int* addresses = (int*) malloc(sizeof(int)*1000);
    if (fp == NULL){
        fprintf(stderr, "No file is found");
        exit(1);
    }

    for(int i =0;i<1000;i++) {
        fscanf(fp,"%d,",&(addresses[i]));
    }
    fclose(fp);
    return addresses;

}

int main() {
    const char* addresses_file = "addresses.txt"; 
    int size;
    int* logical_addresses = read_logical_addresses(addresses_file);
    if (logical_addresses == NULL) {
        return EXIT_FAILURE;
    }

    // Rest code goes here

    // Remember to free the allocated memory
    free(logical_addresses);

    return EXIT_SUCCESS;
}




