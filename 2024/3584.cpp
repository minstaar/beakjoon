#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 15
using namespace std;

int parent[10010];

int Depth(int node)
{
    int cnt = 0;
    while(parent[node] != -1){
        node = parent[node];
        cnt++;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        memset(parent, -1, sizeof(parent));
        for(int i=1; i<=N-1; i++){
            int u, v; cin >> u >> v;
            parent[v] = u;
        }
        
        int n1, n2; cin >> n1 >> n2;
        if(Depth(n1) < Depth(n2)) swap(n1, n2);
        int diff = Depth(n1) - Depth(n2);
        for(; diff>0; diff--){
            n1 = parent[n1];
        }

        if(n1 != n2){
            while(parent[n1] != -1 && parent[n1] != parent[n2]){
                n1 = parent[n1];
                n2 = parent[n2];
            }
            n1 = parent[n1];
        }

        cout << n1 << '\n';
    }

    return 0;
}
