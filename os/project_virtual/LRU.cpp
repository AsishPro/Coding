#include <bits/stdc++.h>
using namespace std;
int page_size = 128;
int page_table_size = 512; //total
int num_of_pages = page_table_size / page_size;
int actual_size = 1024; ///actual mem
int main_offset = actual_size / num_of_pages;
int *actual;
unordered_map<int,int> pagetable;
list<int> lt; // Using a list to implement the LRU queue
int f = 0;

class logical{
    public:
    int page;
    int offset;
    public:
    logical(){}
    logical(int page){
        this->page = page;
        offset = 0;
    }
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
    int index = find(o.page);

    if(o.offset < main_offset)
        return index * main_offset + o.offset;
    else
        cout << "Offset out of range" << endl;
    return -1;
}

void clear_mem(int t){
    int start = t * main_offset;
    int end = start + main_offset;
    memset(&actual[start], -1, main_offset * sizeof(int));
}

int insert(logical o){
    int k = isfree();
    if(find(o.page) != -1){
        // If page is already in memory, move it to the front of the LRU queue
        lt.remove(find(o.page));
        lt.push_front(find(o.page));
        cout << find(o.page) << " and " << o.page << endl;
    } else if(lt.size() == num_of_pages){
        // If memory is full, evict the least recently used page and load the new page
        f++;
        int t = lt.back();
        lt.pop_back();
        clear_mem(t);
        pagetable[t] = o.page;
        cout << t << " " << pagetable[t] << endl;
        lt.push_front(t);
    } else {
        // If memory is not full, load the new page
        f++;
        pagetable[k] = o.page;
        cout << k << " " << pagetable[k] << endl;
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

int main(){
    actual = new int[actual_size];
    memset(actual, -1, actual_size * sizeof(int));
    for(int i = 0; i < num_of_pages; i++) {
        pagetable[i] = -1;
    }
    cout << pagetable.size() << endl;
    
    // int k = insert(logical(1, 56));
    // write(k, 15);
    // read(k);
    // insert(logical(2, 56));
    // insert(logical(3, 56));
    // insert(logical(6, 56));
    // k = insert(logical(4, 56));
    // read(k);
    int i=1;
    while(i < 9){
        logical o2(i, 4);
        int address = insert(o2);
        // cout << address << endl;
        // write(address, 15);
        // read(address); 
        i++;
    }
    logical o3(5, 8);
    insert(o3);
    
    insert(logical(9,10));
    insert(logical(7,10));
    insert(logical(10,10));
    // insert(logical(11,10));

  
    return 0;
}