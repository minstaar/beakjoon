#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<vector<int>> adj;
int l[10000], r[10000];
bool visited[10000];

bool dfs(int a)
{
    if(visited[a]) return false;
    visited[a] = true;
    for(auto b: adj[a]){
        if(r[b] == -1 || !visited[r[b]] && dfs(r[b])){
            l[a] = b, r[b] = a;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;

    while(T--){
        int N, M; cin >> N >> M;
        int cnt = 0;
        vector<string> arr(N);
        for(int i=0; i<N; i++) cin >> arr[i];
        adj = vector<vector<int>>(N*M*2);
        int pv = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j] == '.') cnt++;
                if(arr[i][j] != 'x' && (pv % M) % 2 == 0){
                    if(j != 0){
                        if(i != 0 && arr[i-1][j-1] != 'x') adj[pv].push_back(pv - 1 - M);
                        if(arr[i][j-1] != 'x') adj[pv].push_back(pv - 1);
                        if(i != N - 1  && arr[i+1][j-1] != 'x') adj[pv].push_back(pv - 1 + M);
                    }
                    if(j != M - 1){
                        if(i != 0 && arr[i-1][j+1] != 'x') adj[pv].push_back(pv + 1 - M);
                        if(arr[i][j+1] != 'x') adj[pv].push_back(pv + 1);
                        if(i != N - 1 && arr[i+1][j+1] != 'x') adj[pv].push_back(pv + 1 + M);
                    }
                }
                pv++;
            }
        }
        int res = 0;
        pv = 0;
        memset(l, -1, sizeof(l));
        memset(r, -1, sizeof(r));
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if((pv % M) % 2 == 0){
                    memset(visited, false, sizeof(visited));
                    if(dfs(pv)) res++;
                }
                pv++;
            }
        }
        cout << cnt - res << '\n';
    }

    return 0;
}