#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

int n;
vector<vector<int>> w, dp;

int tsp(int cur, int visited)
{
    if(visited == (1<<n) - 1) return w[cur][0];
    if(dp[cur][visited] != -1) return dp[cur][visited];
    dp[cur][visited] = INF;
    for(int i=0; i<n; i++){
        if((visited & (1<<i)) || w[cur][i] == INF) continue;
        dp[cur][visited] = min(dp[cur][visited], tsp(i, visited | (1<<i)) + w[cur][i]);
    }
    return dp[cur][visited];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n;
    w = vector<vector<int>> (n+1, vector<int>(n+1));
    dp = vector<vector<int>> (n+1, vector<int>(65550, -1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>w[i][j];
            if(w[i][j] == 0) w[i][j] = INF;
        }
    }

    cout<<tsp(0, 1);

    return 0;
}