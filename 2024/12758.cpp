#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;
int N, dp[310][2010];
vector<int> arr[310];

int solve(int cur, int k)
{
    if(cur == N) return 1;
    int &ret = dp[cur][k];
    if(ret != -1) return ret;

    ret = 0;
    int nk = 0;
    if(cur > 0) nk = lower_bound(arr[cur].begin(), arr[cur].end(), arr[cur-1][k]) - arr[cur].begin();
    for(int i=nk; i<arr[cur].size(); i++){
        ret = (ret + solve(cur + 1, i)) % MOD;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        cin >> N;
        for(int i=0; i<N; i++) arr[i].clear();
        for(int i=0; i<N; i++){
            int x; cin >> x;
            for(int j=1; j*j<=x; j++){
                if(x % j == 0){
                    arr[i].push_back(j);
                    if(j != x / j) arr[i].push_back(x / j);
                }
            }
            sort(arr[i].begin(), arr[i].end());
        }

        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0) << '\n';
    }

    return 0;
}