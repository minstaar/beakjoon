#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    while(N--){
        vector<int> a(3), b(3);
        cin >> a[0] >> a[1] >> a[2];
        cin >> b[0] >> b[1] >> b[2];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a[0] ^ b[0] || a[1] ^ b[1] || a[2] ^ b[2] || a[0] * a[0] + a[1] * a[1] != a[2] * a[2]) cout << "NO\n";
        else cout << "YES\n";
    }
    
    return 0;
}