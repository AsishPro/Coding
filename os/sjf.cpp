#include <bits/stdc++.h>
using namespace std;
class process{
    public:
    int at,bt,ct,tt,wt;
};
bool cmp(process p1,process p2){
    if(p1.bt==p2.bt)
     return p1.at<p2.at;
     return p1.bt < p2.bt;
}
bool arv(process p1,process p2){
    if(p1.at==p2.at)
     return p1.bt<p2.bt;
     return p1.at < p2.at;
}
int main(){
    int n;
    cout<<"Number of process: ";
    cin>>n;
    process p[n];
    int min=999;
    for(int i=0;i<n;i++){
        cout<<"arrival time and burst_time of p"<<i<<":";
        cin>>p[i].at>>p[i].bt;
    }   
    sort(p,p+n,cmp);
    sort(p,p+n,arv);
    int total=0;
    for(int i=0;i<n;i++){
        total=max(p[i].at,total);
        p[i].ct=total+p[i].bt;
        total=p[i].ct;    
    }
    int t2=0;
    int t1=0;
    for(int i=0;i<n;i++){
        p[i].tt=p[i].ct-p[i].at;  
        p[i].wt=p[i].tt-p[i].bt;
        t1+=p[i].tt;
        t2+=p[i].wt;
    }
    cout<<"ID\tArrival\tBurst\tComp_time\tTurn_Arnd\tWait_time"<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tt<<"\t"<<p[i].wt<<endl;
    }
    double turn=t1/(double)n;
    double wait=t2/(double)n;
    cout<<"Average turn_around: "<<turn<<endl;
    cout<<"Average waiting_time: "<<wait<<endl;

}