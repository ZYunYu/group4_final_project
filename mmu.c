#include "final_proj.h"
#include <stdio.h>
#include <stdlib.h>

// Function to translate a logical address to a physical address



int handle_page_fault(int page_number, MemoryManagementUnit* mmu) {
    int frame_number = (mmu);
    int page_table_index = get_next_available_page_table_index(mmu);

    if (frame_number == -1 || page_table_index == -1) {
        printf("Error: No available frames or page table entries\n");
        exit(1);
    }

    mmu->pageTable[page_table_index].pageNumber = page_number;
    mmu->pageTable[page_table_index].frameNumber = frame_number;
    mmu->pageTable[page_table_index].valid = 1;

    return frame_number;

}

int translate_page_to_physical(Page* page, MemoryManagementUnit* mmu) {
    int frame_number = check_tlb(page->pageNumber);

    if (frame_number == -1) {  
        frame_number = check_page_table(page->pageNumber);

        if (frame_number == -1) { 
            frame_number = handle_page_fault(page->pageNumber, mmu);
        }

        add_tlb_entry(page->pageNumber, frame_number);
    }

    return combine_frame_number_and_offset(frame_number, page->pageOffset);
}
