#include <bits/stdc++.h>
using namespace std;

class process {
public:
    int at, bt, ct, tt, wt,og;
};

int main(){
    int n;
    cout << "Number of processes: ";
    cin >> n;
    process p[n];
    int added[n]={0};
    for(int i = 0; i < n; i++) {
        cout << "Arrival time and burst time of p" << i << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].og=p[i].bt;
    }
    int total = 0;
    int c= 0;
    while(c < n){
        int idx = -1;
        int min = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(!added[i] && p[i].bt > 0 && p[i].at <= total ){
                if(p[i].bt < min) {
                    added[i]=1;
                    min = p[i].bt;
                    idx = i;
                }
            }
        }
        if(idx != -1){
            total += p[idx].bt;
            p[idx].ct = total;
            p[idx].bt = 0;
            c++;
        } 
        else{
            total++;
        }
    }
    total=0;
    int t2=0;
    for(int i=0;i<n;i++){
            p[i].tt = p[i].ct - p[i].at;
            p[i].wt = p[i].tt - p[i].bt;
            t2 += p[i].tt;
            total+=p[i].wt;
    }
    double turn = 0, wait = 0;
    cout << "ID\tArrival\tBurst\tComp_time\tTurn_Arnd\tWait_time\n";
    for(int i = 0; i < n; i++) {
        cout << i << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tt << "\t" << p[i].wt << endl;    
    }
    turn = t2 / (double)n;
    wait = total / (double)n;
    cout << "Average turn_around: " << turn << endl;
    cout << "Average waiting_time: " << wait << endl;
    return 0;

}