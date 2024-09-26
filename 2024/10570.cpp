#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int ans, cnt = 0;
        map<int, int> m;
        for(int i=0; i<N; i++){
            int a; cin >> a;
            m[a]++;
            if(cnt < m[a]){
                cnt = m[a];
                ans = a;
            }
            else if(cnt == m[a] && ans > a) ans = a;
        }
        cout << ans << '\n';
    }

    return 0;
}