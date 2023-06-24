#include <bits/stdc++.h>
using namespace std;
int wait(int *pro,int n,int *wt){
    for(int i=0;i<n;i++){
        if(i==0)
           wt[i]=0;
        else
        wt[i]=wt[i-1]+pro[i-1];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=wt[i];
    }
    return sum;
}
int turn(int *pro,int *wt,int n,int *trn){
    for(int i=0;i<n;i++)
        trn[i]=wt[i]+pro[i];
    int sum=0;
    for(int i=0;i<n;i++)
          sum+=trn[i];
    return sum;
}
int main(){
    int n;
    cout<<"Enter the Number of Processes: ";
    cin>>n;
    int pro[n];
    for(int i=0;i<n;i++){
        cout<<"Enter process["<<i<<"] burst time: ";
        cin>>pro[i];
    }
    int wt[n],trn[n];
    float w=(wait(pro,n,wt)/(float)n);
    float t=(turn(pro,wt,n,trn)/(float)n);
    cout<<"The Average waiting time : "<<w<<endl;  
    cout<<"The Average turnaround time : "<<t<<endl;
}