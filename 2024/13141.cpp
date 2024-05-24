#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N, M, dist[210][210], longest[210][210];

void floyd()
{
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
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
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    for(int i=0; i<M; i++){
        int u, v, c; cin >> u >> v >> c;
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[u][v], c);
        longest[u][v] = max(longest[u][v], c);
        longest[v][u] = max(longest[v][u], c);
    }

    floyd();

    double ans = INF;
    for(int k=1; k<=N; k++){
        double cur = 0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(longest[i][j] == 0) continue;
                int a = dist[k][i];
                int b = dist[k][j];
                int start = min(a, b);
                double burn = abs(a - b) + (double)(longest[i][j] - abs(a - b)) / 2;
                cur = max(cur, start + burn);
            }
        }
        ans = min(ans, cur);
    }
    cout<<fixed;
    cout.precision(1);
    cout << ans << '\n';

    return 0;
}