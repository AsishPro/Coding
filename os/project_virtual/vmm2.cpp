#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int PAGE_SIZE = 4096; // 4KB page size
const int PAGE_TABLE_SIZE = 1024; // 1KB page table size
const int PHYSICAL_MEMORY_SIZE = 1024* 1024; // 1MB physical memory size
const int NUM_PAGES = PHYSICAL_MEMORY_SIZE / PAGE_SIZE; // Number of physical pages

// Page table entry
struct PageTableEntry {
    bool present; // Is the page present in physical memory?
    int frame; // Physical frame number (if present), otherwise -1
};

// Virtual memory manager
class VirtualMemoryManager {
private:
    vector<PageTableEntry> page_table; // Page table
    queue<int> page_queue; // Page replacement queue
    int page_hits; // Number of page hits
    int page_misses; // Number of page misses
    int* physical_memory; // Physical memory

    // Get the page number for a given virtual address
    int get_page_number(ut address) {  
        return address / PAGE_SIZE;
    }

    // Get the offset for a given virtual address
    int get_offset(int address) {
        cout<<address % PAGE_SIZE<<endl;
        return address % PAGE_SIZE;
    }

    // Get the physical address for a given virtual address
    int get_physical_address(int address) {
        int page_number = get_page_number(address);
        int offset = get_offset(address);
        if (!page_table[page_number].present) {
            
            handle_page_fault(page_number);
        }

        return page_table[page_number].frame * PAGE_SIZE + offset;
    }

    // Handle a page fault for a given page number
    void handle_page_fault(int page_number) {
        page_misses++;
        if (page_queue.size() >= NUM_PAGES) {
            // Evict the oldest page
            int evicted_page = page_queue.front();
            page_queue.pop();
            page_table[evicted_page].present = false;
            page_table[evicted_page].frame = -1;
        }
        // Load the missing page into a free frame
        int frame = find_free_frame();
        page_table[page_number].present = true;
        page_table[page_number].frame = frame;
        page_queue.push(page_number);
    }

    // Find a free physical frame
    int find_free_frame() {
        for (int i = 0; i < NUM_PAGES; i++) {
            cout<<page_table[i].present<<endl;
            if (!page_table[i].present) {
                return i;
            }
        }
        // No free frames, evict the oldest page
        int evicted_page = page_queue.front();
        page_queue.pop();
        page_table[evicted_page].present = false;
        page_table[evicted_page].frame = -1;
        return find_free_frame();
    }

public:
    VirtualMemoryManager() {
        // Initialize page table
        page_table.resize(PAGE_TABLE_SIZE);
        for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
            page_table[i].present = false;
            page_table[i].frame = -1;
        }
        // Initialize page replacement queue
        page_queue = queue<int>();
        // Initialize page hit and miss counters
        page_hits = 0;
        page_misses = 0;
        // Initialize physical memory
        physical_memory = new int[PHYSICAL_MEMORY_SIZE / sizeof(int)];
        memset(physical_memory, 0, PHYSICAL_MEMORY_SIZE);
    }

    ~VirtualMemoryManager() {
        // Deallocate physical memory
        delete[] physical_memory;
    }

    // Read from memory
    int read(int address) {
        int physical_address = get_physical_address(address);
        page_hits++;
        return *(physical_memory + physical_address / sizeof(int));
    }

    // Write to memory
    void write(int address, int value) {
        int physical_address = get_physical_address(address);
        page_hits++;
        // Write the value to physical memory
        *(physical_memory + physical_address / sizeof(int)) = value;
    }

    // Print page hit and miss statistics
    void print_stats() {
        cout << "Page hits: " << page_hits << endl;
        cout << "Page misses: " << page_misses << endl;
    }
};

int main() {
    VirtualMemoryManager vm;
   
    // Read from memory

    // Write to memory
    int address = 0x87654321;
    int value = 0xdeadbeef;
    cout<<value<<endl;
    vm.write(address, value);
    cout<<vm.read(address)<<endl;
    // Print statistics
    vm.read(address);
    vm.print_stats();
    return 0;
}