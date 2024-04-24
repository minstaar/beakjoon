#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int V;
int adj[51][51], friendship[51];

void floyd()
{
    for(int i=1; i<=V; i++) adj[i][i] = 0;
    
    for(int k=1; k<=V; k++){
        for(int i=1; i<=V; i++){
            for(int j=1; j<=V; j++){
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> V;
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            adj[i][j] = INF;
        }
    }
    while(1){
        int a, b; cin >> a >> b;
        if(a == -1 && b == -1) break;
        adj[a][b] = adj[b][a] = 1;
    }

    floyd();

    int ans = INF, cnt = 0;
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            friendship[i] = max(friendship[i], adj[i][j]);
        }
        if(ans > friendship[i]){
            ans = friendship[i];
            cnt = 1;
        }
        else if(ans == friendship[i]) cnt++;
    }
    cout << ans << ' ' << cnt << '\n';
    for(int i=1; i<=V; i++) if(friendship[i] == ans) cout << i << ' ';

    return 0;
}