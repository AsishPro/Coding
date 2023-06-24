#include <bits/stdc++.h>
using  namespace std;
class process{
    vector<int>at,bt,ct,tt,wt;
    double wait,turn;
    int n;
    public:
    void create(){
        cout<<"Number of process: ";
        cin>>n;
        at.resize(n);
        bt.resize(n);
        ct.resize(n);
        tt.resize(n);
        wt.resize(n);
        for(int i=0;i<n;i++){
           cout<<"arrival time and burst_time of p"<<i<<":";
           cin>>at[i]>>bt[i];
        } 
        sort(at.begin(),at.end());
    }
    void completion_time(){
        ct[0]=at[0]+bt[0];
        for(int i=1;i<n;i++){
            ct[i]=max(ct[i-1],at[i])+bt[i];  
        }
    }
    void turn_around_time(){
        int t=0;
        for(int i=0;i<n;i++){
            tt[i]=ct[i]-at[i];
            t+=tt[i];
        }
        turn=t/(double)n;
    }
    void waiting_time(){
        int t=0;
        for(int i=0;i<n;i++){
            wt[i]=tt[i]-bt[i];
            t+=wt[i];
        }
        wait=t/(double)n;
    }
    void print(){
        int t=0;
        cout << setw(3) << left << "ID"
             << setw(8) << left << "Arrival"
             << setw(6) << left << "Burst"
             << setw(10) << left << "Comp_time"
             << setw(10) << left << "Turn_Arnd"
             << setw(10) << left << "Wait_time" << endl;

        for (int i = 0; i < n; i++) {
            cout << setw(3) << left << i
                 << setw(8) << left << at[i]
                 << setw(6) << left << bt[i]
                 << setw(10) << left << ct[i]
                 << setw(10) << left << tt[i]
                 << setw(10) << left << wt[i] << endl;
        }
        // cout<<"ID\tArrival\tBurst\tComp_time\tTurn_Arnd\tWait_time"<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<i<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tt[i]<<"\t"<<wt[i]<<endl;
        // }
        cout<<"Average turn_around: "<<turn<<endl;
        cout<<"Average waiting_time: "<<wait<<endl;
    }


};
int main(){
    process o1;
    o1.create();
    o1.completion_time();
    o1.turn_around_time();
    o1.waiting_time();
    o1.print();
    return 0;
}