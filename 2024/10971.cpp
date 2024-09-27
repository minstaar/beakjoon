#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N, w[15][15], dp[15][1030];

int solve(int cur, int visited)
{
    if(visited == (1 << N) - 1) return  w[cur][0];
    int &ret = dp[cur][visited];
    if(ret != -1) return ret;

    ret = INF;
    for(int i=0; i<N; i++){
        if(visited & (1 << i) || w[cur][i] == INF) continue;
        ret = min(ret, solve(i, visited | (1 << i)) + w[cur][i]);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> w[i][j];
            if(i != j && w[i][j] == 0) w[i][j] = INF;
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1) << '\n';

    return 0;
}