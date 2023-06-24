#include <bits/stdc++.h>
using namespace std;
int page_size=128;
int page_table_size=16;
int actual_size=512;
int num_of_pages=actual_size/page_size;
unordered_map <int,int> pagetable;
queue<int>lt;
int lt_size=0;
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
bool isContains(int x){ 
    queue<int> q=lt;
        while(!q.empty()){ 
            if(q.front() == x) 
                return true; 
            q.pop(); 
        } 
        return false; 
} 
int find(int x){
    for(int i=0;i<pagetable.size();i++)
      if(pagetable[i]==x)
         return i;
    return -1;
}


void insert(logical o){
    int k=isfree();
    
    if(k!=-1 && !isContains(k)){
        lt_size=(lt_size+1)%page_size;
        pagetable[k]=o.page;
        cout<<k<<" "<<pagetable[k]<<endl;
        lt.push(k);
    }
    else if(!isContains(o.page)){
       f++;
       int top=lt.front();
       pagetable[top]=-1;
       lt.pop();
       k=isfree();
       pagetable[k]=o.page;
       cout<<k<<" "<<pagetable[top]<<endl;      
       lt.push(k);
    }
    else{
        cout<<"Page at : "<<
    }
}


int main(){
    for(int i = 0; i < num_of_pages; i++) {
        pagetable[i] = -1;
    }
    int i=0;
    while(i<10){
        logical o2(i,128);
        insert(o2);
        i++;
    }
    logical o3(2,128);
    insert(o3);
    return 0;
}
