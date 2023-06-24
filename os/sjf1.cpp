#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;
class p
{
public:
    int a, b, c, tat, wt, in;
};
bool comp(p p1, p p2)
{
    if (p1.b == p2.b)
        return p1.a < p2.a;
    return p1.b < p2.b;
}
int main()
{
    vector<p> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        p process;
        cin >> a >> b;
        process.a = a;
        process.b = b;
        process.in = i + 1;
        q.push_back(process);
    }

    sort(q.begin(), q.end(), comp);

    int tt = 0;
    for (int i = 0; i < n; i++)
    {
        if (q[i].a < tt)
        {
            q[i].c = tt + q[i].b;
            tt = q[i].c;
        }
        else
        {
            int diff = q[i].a - tt;
            tt += diff;
            q[i].c = tt + q[i].b;
            tt = q[i].c;
        }
    }
    for (int i = 0; i < n; i++)
    {
        q[i].tat = q[i].c - q[i].a;
        q[i].wt = q[i].tat - q[i].b;
    }

    cout << "in\t"
         << "at\t"
         << "bt\t"
         << "ct\t"
         << "tat\t"
         << "wt\t" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << q[i].in << "\t" << q[i].a << "\t" << q[i].b << "\t" << q[i].c << "\t" << q[i].tat << "\t" << q[i].wt << endl;
    }
}