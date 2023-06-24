#include <bits/stdc++.h>
using namespace std;
int page_size=128;
int page_table_size=512; //total
int num_of_pages=page_table_size/page_size;
int actual_size=1024; ///actual mem
int main_offset=actual_size/num_of_pages;
int *actual;
unordered_map <int,int> pagetable;
queue<int>lt;
int index=0;
int f=0;
class logical{
    public:
    int page;
    int offset;
    public:
    logical(){}
    logical(int page){
        this->page=page;
        offset=0;
    }
    logical(int page,int offset){
        this->page=page;
        this->offset=offset;
    } 
};
int isfree(){
    for(int i=0;i<pagetable.size();i++)
      if(pagetable[i]==-1)
         return i;
    return -1;
}
// bool isContains(int x){ 
//     queue<int> q=lt;
//         while(!q.empty()){ 
//             if(q.front() == x) 
//                 return true; 
//             q.pop(); 
//         } 
//         return false; 
// } 
int find(int x){
    for(int i=0;i<pagetable.size();i++)
      if(pagetable[i]==x)
         return i;
    return -1;
}

int physical(logical o){
    int index=find(o.page);

    if(o.offset<main_offset)
        return index*main_offset+(o.offset);
    else
    cout<<"Offset out of range"<<endl;
    return -1;
}
void clear_mem(int t){
    int start=t*main_offset;
    int end=start+main_offset;
    memset(&actual[start], -1, main_offset * sizeof(int));
}
int insert(logical o){
    int k=isfree();
    if(find(o.page)!=-1)
        cout<<find(o.page)<<" and  "<<o.page<<" "<<endl;
    else if(lt.size()==num_of_pages){
        f++;
        int t=lt.front();
        // pagetable[t]=-1;   free position and then find 
        // k=isfree();
        clear_mem(t);
        lt.pop();
        pagetable[t]=o.page;
        cout<<t<<" "<<pagetable[t]<<endl;
        lt.push(t);
    }
    else{
        //if not in page table bring in it
        f++;
        // index=(index)%num_of_pages;
        // index++;
        pagetable[k]=o.page;
        cout<<k<<" "<<pagetable[k]<<endl;
        lt.push(k);
    }
    return physical(o);
}
void write(int address,int data){
    actual[address]=data;
}
void read(int address){
    cout<<actual[address]<<endl;
}

int main(){
    actual=new int[actual_size];
    memset(actual, -1, actual_size * sizeof(int));
    for(int i = 0; i < num_of_pages; i++) {
        pagetable[i] = -1;
    }
    cout<<pagetable.size()<<endl;
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
