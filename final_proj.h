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

// TLB functions
void add_tlb_entry();
int check_tlb();

// Page table function 
void add_to_page_table();
int check_page_table();

// pages function 
int* read_addresses();

int get_page_number(int logical_address);

int get_offsef(int logical_address);

Page* convert_addresses(int* addresses);

// frames functions 

void read_from_backing_store(unsigned char* physicalMemory, int frameNumber, const char* backingStoreFile);






