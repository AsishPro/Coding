#include <iostream>
#include <queue>
#include <climits>
class PageTable {
public:
    PageTable(int page_size, int num_pages) {
        this->page_size = page_size;
        this->num_pages = num_pages;
        table = new int[num_pages];
        for(int i=0; i<num_pages; i++) {
            table[i] = -1;
}
    }
~PageTable() {
        delete[] table;
}
    void map(int page_num, int frame_num) {
table[page_num] = frame_num;
    }
    void unmap(int page_num) {
        table[page_num] = -1;
}
    int get_frame(int page_num) {
        return table[page_num];
}
private:
    int* table;
    int page_size;
    int num_pages;
};
class LRUReplacement {
public:
    LRUReplacement(int num_frames) {
        this->num_frames = num_frames;
        frames = new int[num_frames];
        for(int i=0; i<num_frames; i++) {
            frames[i] = -1;
}
        timestamps = new int[num_frames];
        for(int i=0; i<num_frames; i++) {
            timestamps[i] = -1;
}
    }
~LRUReplacement() {
        delete[] frames;
        delete[] timestamps;
}
    int choose_frame() {
        int min_timestamp = INT_MAX;
        int min_index = -1;
        for(int i=0; i<num_frames; i++) {
            if(timestamps[i] < min_timestamp) {
min_timestamp = timestamps[i];
                min_index = i;
            }
        }
        return min_index;
}
    void update_timestamp(int frame_num, int timestamp) {
timestamps[frame_num] = timestamp;
    }
    void add_frame(int frame_num) {
        int index = choose_frame();
frames[index] = frame_num;
    }
    void remove_frame(int frame_num) {
        for(int i=0; i<num_frames; i++) {
            if(frames[i] == frame_num) {
                frames[i] = -1;
                timestamps[i] = -1;
                break;
}
        }
    }
private:
    int* frames;
    int* timestamps;
    int num_frames;
};
class MemoryManager {
public:
    MemoryManager(int page_size, int num_pages, int num_frames) {
        this->page_size = page_size;
        this->num_pages = num_pages;
        this->num_frames = num_frames;
        page_table = new PageTable(page_size, num_pages);
        page_replacement = new LRUReplacement(num_frames);
        frames = new char[num_frames * page_size];
        for(int i=0; i<num_frames; i++) {
free_frames.push(i);
        }
    }
~MemoryManager() {
        delete page_table;
        delete page_replacement;
        delete[] frames;
}
    void* allocate(int num_bytes) {
        int num_pages_needed = (num_bytes + page_size - 1) / page_size;
        int* page_nums = new int[num_pages_needed];
        for(int i=0; i<num_pages_needed; i++) {
page_nums[i] = allocate_page();
            if(page_nums[i] == -1) {
                // Out of memory
                return nullptr;
}
        }
        void* ptr = frames + page_nums[0] * page_size;
        delete[] page_nums;
        return ptr;
}
    void deallocate(void* ptr, int num_bytes) {
        int page_num = ((char*)ptr - frames) / page_size;
        int num_pages = (num_bytes + page_size - 1) / page_size;
        for(int i=0; i<num_pages; i++) {
deallocate_page(page_num + i);
        }
    }
private:
    int allocate_page() {
        if(free_frames.empty()) {
            int frame_num = page_replacement->choose_frame();
            int page_num = page_table->get_frame(frame_num);
page_table->unmap(page_num);
            page_replacement->remove_frame(frame_num);
            free_frames.push(frame_num);
        }
        int frame_num = free_frames.front();
free_frames.pop();
        int page_num = find_free_page();
        page_table->map(page_num, frame_num);
page_replacement->add_frame(frame_num);
        return page_num;
}
    void deallocate_page(int page_num) {
        int frame_num = page_table->get_frame(page_num);
page_table->unmap(page_num);
        page_replacement->remove_frame(frame_num);
        free_frames.push(frame_num);
    }
    int find_free_page() {
        for(int i=0; i<num_pages; i++) {
            if(page_table->get_frame(i) == -1) {
                return i;
}
        }
        return -1;
}
private:
PageTable* page_table;
    LRUReplacement* page_replacement;
    char* frames;
    int page_size;
    int num_pages;
    int num_frames;
    std::queue<int> free_frames;
};
void write_page_to_disk(int page_num, char* data) {
    // Write the data to a free area on the disk
    // Update the page table to indicate that the page is now stored on the disk
}
void read_page_from_disk(int page_num, char* data) {
    // Read the data from the disk into the provided buffer
}
int main() {
    const int PAGE_SIZE = 4096;
    const int NUM_PAGES = 1000;
    const int NUM_FRAMES = 100;
    MemoryManager mem_manager(PAGE_SIZE, NUM_PAGES, NUM_FRAMES);
    // Allocate memory
    void* ptr1 = mem_manager.allocate(1024);
    void* ptr2 = mem_manager.allocate(8192);
    if(ptr1 == nullptr || ptr2 == nullptr) {
        std::cout << "Error: Out of memory" << std::endl;
        return 1;
}
    // Use the memory
    *(int*)ptr1 = 42;
    char* data = (char*)ptr2;
    for(int i=0; i<8192; i++) {
        data[i] = 'a';
}
    // Deallocate memory
    mem_manager.deallocate(ptr1, 1024);
    mem_manager.deallocate(ptr2, 8192);
    return 0;
}
