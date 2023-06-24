#include <bits/stdc++.h>
using namespace std;
class process{
    vector<int>at,bt,ct,tt,wt,og;
    double wait,turn;
    int n,t,total=0,t2=0;
    public:
    void create(){
        cout<<"Enter the time quantum: ";
        cin>>t;
        cout<<"Number of process: ";
        cin>>n;
        at.resize(n);
        bt.resize(n);
        ct.resize(n);
        tt.resize(n);
        wt.resize(n);
        for(int i=0;i<n;i++){
            cout<<"Arrival time and burst time of p"<<i<<":";
            cin>>at[i]>>bt[i];
        }   
    }
    void completion_time(){
        int added[n]={0};
        queue<int>q;
        total=0;
        og=bt;
        int c=0;
        while(c!=n){
            for(int i=0;i<n;i++){
                if(!added[i] && at[i]<=total && bt[i]>0 ){
                    added[i]=1;
                    q.push(i);
                }     
            }
            if(!q.empty()){
                int id=q.front();
                q.pop();
                if(bt[id]<=t){
                    total+=bt[id];
                    ct[id]=total;
                    bt[id]=0; 
                    c++;  
                } 
                else{
                total+=t;
                bt[id]=bt[id]-t;
                q.push(id); 
                }
            }
            else
            total++;
        }
        total=0;
        t2=0;
        for(int i=0;i<n;i++){
            tt[i]=ct[i]-at[i];
            wt[i]=tt[i]-og[i];
            total+=tt[i];
            t2+=wt[i];
        }        
    }
    void print(){
        cout << setw(3) << left << "ID"
             << setw(8) << left << "Arrival"
             << setw(6) << left << "Burst"
             << setw(10) << left << "Comp_time"
             << setw(10) << left << "Turn_Arnd"
             << setw(10) << left << "Wait_time" << endl;

        for (int i = 0; i < n; i++) {
            cout << setw(3) << left << i
                 << setw(8) << left << at[i]
                 << setw(6) << left << og[i]
                 << setw(10) << left << ct[i]
                 << setw(10) << left << tt[i]
                 << setw(10) << left << wt[i] << endl;
        }
        turn=total/(double)n;
        wait=t2/(double)n;
        cout<<"Average turn_around: "<<turn<<endl;
        cout<<"Average waiting_time: "<<wait<<endl;
    }

};
int main(){
    process o1;
    o1.create();
    o1.completion_time();
    o1.print();
    return 0;
}