#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int base=50000;
    float da=0.32*base;
    float hra=0.28*base;
    float ma=0.06*base;
    float ta=0.09*base; 
    float special=0.25*base;
    float pt=200;
    float pf=(base+da)*0.12;
    float ctc=base+da+hra+special+ma+ta;
    float net=ctc-pf-pt;
    float tds=(net*12);
    if(tds>500000)
    tds=12500+0.10*(tds);
    else
    tds=tds*0.05;
    cout<<ctc<<' '<<net<<' '<<tds;
}