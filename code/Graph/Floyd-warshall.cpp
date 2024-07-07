#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>> dist(1010, vector<ll>(1010, 1e18));

void floyd(int n){
    for(int i=1; i<=n; i++) dist[i][i] = 0;
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void addEdge(int u, int v, int w){
    dist[u][v] = w;
}