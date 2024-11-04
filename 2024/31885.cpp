#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll N, K;
pll E;
vector<pll> arr(200010);
set<pll> s;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> arr[i].first >> arr[i].second;
        s.insert(arr[i]);
    }
    cin >> E.first >> E.second;

    auto getDist = [&](pll a, pll b){
        return abs(a.first - b.first) + abs(a.second - b.second);
    };

    ll ans = getDist({0, 0}, E);

    for(int i=0; i<N; i++){
        ll tmp = getDist(arr[i], E);
        if(tmp <= K - 2){
            ans = min(ans, tmp + 2);
            if(ans < 4) break;
            continue;
        }
        if(K < 4) continue;
        
        if(s.find({E.first - arr[i].first, E.second - arr[i].second}) != s.end()){
            ans = min(ans, 4LL);
            continue;
        }
        for(int j=0; j<4; j++){
            ll x = E.first + "1210"[j] - '1';
            ll y = E.second + "2101"[j] - '1';
            if(s.find({x - arr[i].first, y - arr[i].second}) != s.end()){
                ans = min(ans, 5LL);
                break;
            }
        }
    }

    if(ans > K) cout << "-1\n";
    else cout << ans << '\n';

    return 0;
}