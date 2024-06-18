#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
struct Data{
    ll l, v;
    bool isReach = false;
    bool operator < (const Data &other) const{
        return l > other.l;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for(int q=1; q<=T; q++){
        int n, k, b, t; cin >> n >> k >> b >> t;
        vector<Data> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i].l;
        }
        for(int i=0; i<n; i++){
            cin >> arr[i].v;
            arr[i].isReach = arr[i].l + t * arr[i].v >= b;
        }
        sort(arr.begin(), arr.end());
        int possible = 0, impossible = 0, ans = 0;
        for(int i=0; i<n; i++){
            if(arr[i].isReach){
                possible++;
                ans += impossible;
                if(possible == k) break;
            }
            else impossible++;
        }
        cout << "Case #" << q << ": ";
        if(possible < k) cout << "IMPOSSIBLE" <<'\n';
        else cout << ans << '\n';
    }

    return 0;
}