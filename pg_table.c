#include "final_proj.h"

PageTableEntry pageTable[PAGE_TABLE_SIZE];

void init_page_table() {
    for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
        pageTable[i].isValid = 0;
    }
}

void add_page_table_entry(int pageNumber, int frameNumber) {
    pageTable[pageNumber].frameNumber = frameNumber;
    pageTable[pageNumber].isValid = 1;
}

int check_page_table(int pageNumber) {
    if (pageTable[pageNumber].isValid) {
        return pageTable[pageNumber].frameNumber;
    }
    return -1;
}



int main(int argc, char *argv[]){

    
}
