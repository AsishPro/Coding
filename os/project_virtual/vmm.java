package project_virtual;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class vmm{
    private static final int PAGE_SIZE = 4096; // 4KB page size
    private static final int PAGE_TABLE_SIZE = 1024; // 1KB page table size
    private static final int PHYSICAL_MEMORY_SIZE = 1024 * 1024; // 1MB physical memory size
    private static final int NUM_PAGES = PHYSICAL_MEMORY_SIZE / PAGE_SIZE; // Number of physical pages

    // Page table entry
    private static class PageTableEntry {
        boolean present; // Is the page present in physical memory?
        int frame; // Physical frame number (if present), otherwise -1
    }

    private final PageTableEntry[] pageTable; // Page table
    private final Queue<Integer> pageQueue; // Page replacement queue
    private int pageHits; // Number of page hits
    private int pageMisses; // Number of page misses
    private final int[] physicalMemory; // Physical memory

    public vmm() {
        // Initialize page table
        pageTable = new PageTableEntry[PAGE_TABLE_SIZE];
        Arrays.fill(pageTable, new PageTableEntry());
        // Initialize page replacement queue
        pageQueue = new LinkedList<>();
        // Initialize page hit and miss counters
        pageHits = 0;
        pageMisses = 0;
        // Initialize physical memory
        physicalMemory = new int[PHYSICAL_MEMORY_SIZE / Integer.BYTES];
        Arrays.fill(physicalMemory, 0);
    }

    // Get the page number for a given virtual address
    private int getPageNumber(int address) {
        return address / PAGE_SIZE;
    }

    // Get the offset for a given virtual address
    private int getOffset(int address) {
        return address % PAGE_SIZE;
    }

    // Get the physical address for a given virtual address
    private int getPhysicalAddress(int address) {
        int pageNumber = getPageNumber(address);
        int offset = getOffset(address);
        if (!pageTable[pageNumber].present) {
            handlePageFault(pageNumber);
        }
        return pageTable[pageNumber].frame * PAGE_SIZE + offset;
    }

    // Handle a page fault for a given page number
    private void handlePageFault(int pageNumber) {
        pageMisses++;
        if (pageQueue.size() >= NUM_PAGES) {
            // Evict the oldest page
            int evictedPage = pageQueue.poll();
            pageTable[evictedPage].present = false;
            pageTable[evictedPage].frame = -1;
        }
        // Load the missing page into a free frame
        int frame = findFreeFrame();
        pageTable[pageNumber].present = true;
        pageTable[pageNumber].frame = frame;
        pageQueue.offer(pageNumber);
    }

    // Find a free physical frame
    private int findFreeFrame() {
        for (int i = 0; i < NUM_PAGES; i++) {
            if (!pageTable[i].present) {
                return i;
            }
        }
        // No free frames, evict the oldest page
        int evictedPage = pageQueue.poll();
        pageTable[evictedPage].present = false;
        pageTable[evictedPage].frame = -1;
        return findFreeFrame();
    }

    // Read from memory
    public int read(int address) {
        int physicalAddress = getPhysicalAddress(address);
        pageHits++;
        return physicalMemory[physicalAddress / Integer.BYTES];
    }

    // Write to memory
    public void write(int address, int value) {
        int physicalAddress = getPhysicalAddress(address);
        pageHits++;
        // Write the value to physical memory
        physicalMemory[physicalAddress / Integer.BYTES] = value;
    }

    // Print page hit and miss statistics
    public void printStats() {
        System.out.println("Page hits: " + pageHits);
        System.out.println("Page misses: " + pageMisses);
    }
    public static void main(String[] args){
        vmm o1=new vmm();
        int address = 0x87654321;
        int value = 0xdeadbeef;
        o1.write(address,value);

    }
}