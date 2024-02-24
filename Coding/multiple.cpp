#include<iostream>
using namespace std;
template<class T>
class search
{
    public:
    T n;
    T arr[100];
    T b;
    search(T  a,T brr[])
    {
        n=a;
        for(int i=0;i<n;i++)
        arr[i]=brr[i];
    }
    void searchin(T c)
    {
        b=c;
        for( int i=0;i<n;i++)
        {
            if(arr[i]==b)
            {
                cout<<"HIT"<<endl;
            }
        }

    }

};
int main()
{
    int a;
    cin>>a;
    int arr[a];
    for(int i=0;i<a;i++)
    {
        cin>>arr[i];
    }
    int b;
    cin>>b;
    search <int> a1(a,arr);
    a1.searchin(b);
}