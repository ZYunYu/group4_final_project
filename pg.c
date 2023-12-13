#include "final_proj.h"
#include <stdlib.h>
#include <stdio.h>
Page* pages;

Page* convert_addresses(int* addresses) {
    pages =(Page*) malloc(sizeof(Page) *1000);
    for (size_t i = 0; i < 1000; i++){
        Page* current  =  malloc(sizeof(Page));
        current->pageNumber = get_page_number(addresses[i]);
        current->pageOffset = get_page_offset(addresses[i]);
        pages[i] = *current;
        free(current);
    }

    return pages; 
    

}


int get_page_number(int logical_address) {
    int page_number = (logical_address >> 8) & 0x00FF;
    return page_number;
}

int get_page_offset(int logical_address) {
    int offset = logical_address & 0x00FF;
    return offset;
}


