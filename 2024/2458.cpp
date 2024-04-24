#include <iostream>
#define INF 1e9
using namespace std;

int N, M;
int adj[510][510];

void floyd()
{
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
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

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            adj[i][j] = INF;
        }
    }

    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        adj[a][b] = 1;
    }

    floyd();

    int ans = 0;
    for(int i=1; i<=N; i++){
        int cnt = 0;
        for(int j=1; j<=N; j++){
            if(adj[i][j] != INF || adj[j][i] != INF) cnt++;
        }
        if(cnt == N - 1) ans++;
    }
    cout << ans << '\n';

    return 0;
}