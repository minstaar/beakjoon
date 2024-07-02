#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for(int t=1; t<=T; t++){
        int n, m; cin >> n >> m;
        map<int, int> mp1, mp2;
        for(int i=0; i<n; i++){
            int a; cin >> a;
            for(int x=2; x*x<=a; x++){
                while(a % x == 0){
                    mp1[x]++;
                    a /= x;
                }
            }
            if(a > 1) mp1[a]++;
        }
        for(int i=0; i<m; i++){
            int b; cin >> b;
            for(int x=2; x*x<=b; x++){
                while(b % x == 0){
                    if(mp1[x] != 0) mp1[x]--;
                    else mp2[x]++;
                    b /= x;
                }
            }
            if(b > 1){
                if(mp1[b] != 0) mp1[b]--;
                else mp2[b]++;
            }
        }
        int res1 = 1, res2 = 1;
        for(auto x: mp1) res1 *= pow(x.first, x.second);
        for(auto x: mp2) res2 *= pow(x.first, x.second);
        cout << "Case #" << t << ": ";
        cout << res1 << " / " << res2 << '\n';
    }

    return 0;
}