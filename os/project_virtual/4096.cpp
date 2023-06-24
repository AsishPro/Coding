#include <bits/stdc++.h>
using namespace std;
int page_size = 128;  // also frame size
int page_table_size = 512; //total
int num_of_pages = page_table_size / page_size;
int actual_size = 1024; ///actual mem
int num_of_frames=actual_size/page_size; // pagesize=framesize
int *actual;
unordered_map<int,int> pagetable;
list<int> lt; // Using a list to implement the LRU queue
int f = 0;

class logical{
    public:
    int page;
    int offset;
    int address;
    public:
    logical(){}
    logical(int page,int offset){
        this->page = page;
        this->offset = offset;
    } 
};

int isfree(){
    for(int i = 0; i < num_of_pages; i++)
        if(pagetable[i] == -1)
            return i;
    return -1;
}

int find(int x){
    for(int i = 0; i < num_of_pages; i++)
        if(pagetable[i] == x)
            return i;
    return -1;
}

int physical(logical o){
    //page number starts with 1
    if(o.offset < page_size){
        o.address=((o.page-1)%num_of_frames)*page_size+o.offset;
        return o.address;
    }
    else
        cout << "Offset out of range" << endl;
    return -1;
}

void clear_mem(int p){
    int start = (p-1) * page_size;
    int end = start + page_size;
    for(int i=start;i<=end;i++){
        actual[i]=-1;
    }
}

int insert(logical o){
    int k = isfree();
    if(find(o.page) != -1){
        // If page is already in memory, move it to the front of the LRU queue
        lt.remove(find(o.page));
        lt.push_front(find(o.page));
    } else if(lt.size() == num_of_pages){
        // If memory is full, evict the least recently used page and load the new page
        f++;
        int t = lt.back();
        lt.pop_back();
        clear_mem(pagetable[t]);
        pagetable[t] = o.page; //inserting new page
        lt.push_front(t);
    } else {
        // If memory is not full, load the new page
        f++;
        pagetable[k] = o.page;
        lt.push_front(k);
    }
    return physical(o);
}

void write(int address,int data){
    actual[address] = data;
}

void read(int address){
    cout << actual[address] << endl;
}

void page_fault(){
    cout<<"Number of page faults: "<<f<<endl;
}

void display_queue() {
    cout << "LRU Queue:" << endl;
    for(int page_index: lt) {
        cout << pagetable[page_index] << " ";
    }
    cout << endl;
}

void display_pagetable() {
    cout << "Page Table:" << endl;
    for(int i = 0; i < num_of_pages; i++) {
        if(pagetable[i] != -1) {
            cout << "Page:" << i << " Frames:" << pagetable[i] << endl;
        }
    }
    page_fault();
}

int main(){
    actual = new int[actual_size]; 
    memset(actual, -1, actual_size * sizeof(int));
    for(int i = 0; i < num_of_pages; i++) {
        pagetable[i] = -1; //empty pages
    }
    
    int choice = -1;
    while(choice != 0){
        cout << "Virtual Memory Manager" << endl;
        cout << "----------------------" << endl;
        cout << "1. Write to memory" << endl;
        cout << "2. Read from memory" << endl;
        cout << "3. Display page table" << endl;
        cout << "4. Display LRU queue" << endl;
        cout << "5. Page faults" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch(choice){
            case 1: {
                int page, offset, data;
                cout << "Enter page number: ";
                cin >> page;
                cout << "Enter offset: ";
                cin >> offset;
                cout << "Enter data: ";
                cin >> data;
                int address = insert(logical(page, offset));
                write(address, data);
                break;
            }
            case 2: {
                int page, offset;
                cout << "Enter page number: ";
                cin >> page;
                cout << "Enter offset: ";
                cin >> offset;
                int address = physical(logical(page, offset));
                read(address);
                break;
            }
            case 3:
                display_pagetable();
                break;
            case 4:
                display_queue();
                break;
            case 5:
                page_fault();
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
        cout << endl;
    }

    return 0;
}