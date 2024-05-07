#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 19
using namespace std;

vector<int> adj[100010];
int dp[100010][MAX];

int TreeDFS(int parent, int curNode, int curColor)
{
    if(dp[curNode][curColor] != 0) return dp[curNode][curColor];
    int child = 0;
    for(auto next: adj[curNode]){
        if(next == parent) continue;
        int tmp = 1e9;
        for(int i=1; i<=MAX-1; i++){
            if(i == curColor) continue;
            tmp = min(tmp, TreeDFS(curNode, next, i));
        }
        child += tmp;
    }
    return dp[curNode][curColor] = child + curColor;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=1; i<=N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 1e9;
    for(int i=1; i<=MAX-1; i++){
        ans = min(ans, TreeDFS(0, 1, i));
    }
    cout << ans << '\n';

    return 0;
}