#include <stdio.h>
#include <stdlib.h>

int* read_logical_addresses(const char* filename, int* size) {
    FILE* file = fopen(filename, "r");

    // Allocate memory for logical addresses
    int* addresses = malloc(1000 * sizeof(int)); // 1000 addresses
    int addr;
    *size = 0;

    while (fscanf(file, "%d", &addr) == 1) {
        addresses[*size] = addr;
        (*size)++;
    }

    fclose(file);
    return addresses;
}

int main() {
    const char* addresses_file = "addresses.txt"; 
    int size;
    int* logical_addresses = read_logical_addresses(addresses_file, &size);

    if (logical_addresses == NULL) {
        return EXIT_FAILURE;
    }

    // Rest code goes here

    // Remember to free the allocated memory
    free(logical_addresses);

    return EXIT_SUCCESS;
}




