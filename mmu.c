#include "final_proj.h"
#include <stdio.h>
#include <stdlib.h>



// Function to translate a logical address to a physical address



// int handle_page_fault(int page_number, MemoryManagementUnit* mmu) {
// }

// void translate_logical_to_physical(int page_number,int frame_number ) {
//     // gets specefied page number 
//     // creates new frames struct where 
// }

// int translate_page_to_physical(Page* page, MemoryManagementUnit* mmu) {
//     int frame_number = check_tlb(page->pageNumber);

//     if (frame_number == -1) {  
//         frame_number = check_page_table(page->pageNumber);

//         if (frame_number == -1) { 
//             frame_number = handle_page_fault(page->pageNumber, mmu);
//         }

//         add_tlb_entry(page->pageNumber, frame_number);
//     }

//     return combine_frame_number_and_offset(frame_number, page->pageOffset);
// }
