#define VIRTUAL_MEMORY_SIZE 65536  // 65,536 bytes
#define PAGE_SIZE 256  // Page size of 2^8 bytes
#define FRAME_SIZE 256  // 256 frames
#define TOTAL_FRAMES 256  // Total number of frames in physical memory
#define TLB_SIZE 16  // 16 entries in the TLB
#define PAGE_TABLE_SIZE 256  // 2^8 entries in the page table




// page table entry
typedef struct {
    int isValid;
    int frameNumber;
} PageTableEntry;

extern PageTableEntry pageTable[PAGE_TABLE_SIZE];

// TLB entry
typedef struct {
    int pageNumber;
    int frameNumber;
    int isValid;
} TLBEntry;

typedef struct {
    PageTableEntry pageTable[PAGE_TABLE_SIZE];
    TLBEntry tlb[TLB_SIZE];
    char pMemory[TOTAL_FRAMES][FRAME_SIZE];
} MemoryManagementUnit;


typedef struct{
    int pageNumber;
    int pageOffset;
} Page;

typedef struct{
    int frameNumber;
    int Offset;
} Frame;



// TLB functions
extern void add_tlb_entry();
extern int check_tlb();

// Page table function 
extern void add_to_page_table();
extern int check_page_table();

// pages function 
int* read_addresses(char* filename);

int get_page_number(int logical_address);

int get_offsef(int logical_address);

Page* convert_addresses(int* addresses);

extern Page* get_page(Page* pages,int page_number);

// frames functions 

extern signed char* read_from_backing_store(int frameNumber, const char* backingStoreFile);

// mmu function 

void translate_logical_to_physical();  //   

void handle_page_fault(); // check page table if empty read from backing store then update page table with frame number 









