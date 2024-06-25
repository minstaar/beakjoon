#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

const int INF = 1e9;
vector<pii> dp(1000010, {-INF, INF});

pii solve(int k)
{
    if(k <= 1) return {-INF, INF};
    else if(k == 2) return {1, 1};
    else if(k == 3) return {2, 2};
    pii &ret = dp[k];
    if(ret != make_pair(-INF, INF)) return ret;
    for(int i=2; i<=k-2; i++){
        pii a = solve(k - i);
        pii b = solve(i);
        ret.first = max(ret.first, a.first + b.first);
        ret.second = min(ret.second, a.second + b.second);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    pii ans = solve(N);
    cout << ans.second << ' ' << ans.first << '\n';

    return 0;
}