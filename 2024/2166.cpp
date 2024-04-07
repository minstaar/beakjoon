#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    long long det1 = 0, det2 = 0;
    long long x1, y1; cin>>x1>>y1;
    long long tx = x1, ty = y1;
    for(int i=0; i<n-1; i++){
        long long x2, y2; cin>>x2>>y2;
        det1 += x1 * y2;
        det2 += x2 * y1;
        x1 = x2;
        y1 = y2;
    }
    det1 += x1 * ty;
    det2 += y1 * tx;

    cout<<fixed;
    cout.precision(1);
    cout<<abs((double)det1 - det2) / 2;
    
    return 0;
}
