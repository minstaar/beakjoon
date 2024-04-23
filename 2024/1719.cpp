#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
#define INF 1e14
using namespace std;

int V, E;
ll adj[210][210], via[210][210];
vector<int> path;

void reconstruct(int u, int v)
{
    if(via[u][v] == -1){
        path.push_back(u);
        if(u != v){
            path.push_back(v);
        }
    }
    else{
        reconstruct(u, via[u][v]);
        path.pop_back();
        reconstruct(via[u][v], v);
    }
}

void floyd()
{
    memset(via, -1, sizeof(via));
    for(int k=1; k<=V; k++){
        for(int i=1; i<=V; i++){
            for(int j=1; j<=V; j++){
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                    via[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> V >> E;
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            adj[i][j] = INF;
        }
    }
    for(int i=0; i<E; i++){
        int a, b, w; cin >> a >> b >> w;
        if(adj[a][b] > w) adj[a][b] = w;
        if(adj[b][a] > w) adj[b][a] = w;
    }

    floyd();

    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            if(i == j || adj[i][j] == INF){
                cout << "- ";
                continue;
            }
            else{
                path.clear();
                reconstruct(i, j);
                cout << path[1] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}