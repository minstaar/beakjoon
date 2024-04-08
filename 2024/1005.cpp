#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> node;
vector<vector<int>> edge;
vector<int> dp;

int dfs(int x)
{
    if(dp[x] != -1) return dp[x];
    int time = 0;
    for(auto i: edge[x]){
        time = max(time, dfs(i));
    }
    return dp[x] = time + node[x];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin>>T;
    while(T--){
        int n, k; cin>>n>>k;
        int w;
        node = vector<int>(n+1);
        edge = vector<vector<int>>(n+1);
        dp = vector<int>(n+1, -1);
        for(int i=1; i<=n; i++) cin>>node[i];
        for(int i=0; i<k; i++){
            int a, b; cin>>a>>b;
            edge[b].push_back(a);
        }
        cin>>w;
        
        cout<<dfs(w)<<'\n';
    }

    return 0;
}
