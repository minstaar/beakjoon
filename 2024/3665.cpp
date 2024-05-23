#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

bool adj[510][510];
int inDegree[510];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        memset(adj, false, sizeof(adj));
        memset(inDegree, 0, sizeof(inDegree));
        int N; cin >> N;
        vector<int> arr, res;
        for(int i=0; i<N; i++){
            int a; cin >> a;
            for(auto j: arr){
                adj[j][a] = true;
                inDegree[a]++;
            }
            arr.push_back(a);
        }
        int M; cin >> M;
        for(int i=0; i<M; i++){
            int a, b; cin >> a >> b;
            if(adj[a][b]){
                adj[a][b] = false;
                inDegree[b]--;
                adj[b][a] = true;
                inDegree[a]++;
            }
            else{
                adj[b][a] = false;
                inDegree[a]--;
                adj[a][b] = true;
                inDegree[b]++;
            }
        }

        queue<int> que;
        for(int i=0; i<N; i++){
            if(inDegree[arr[i]] == 0){
                que.push(arr[i]);
                res.push_back(arr[i]);
                break;
            }
        }
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            for(int i=1; i<=N; i++){
                if(!adj[cur][i]) continue;
                inDegree[i]--;
                if(inDegree[i] == 0){
                    que.push(i);
                    res.push_back(i);
                }
            }
        }
        if(res.size() < N){
            cout << "IMPOSSIBLE" << '\n';
        }
        else{       
            for(int i=0; i<N; i++) cout << res[i] << ' ';
            cout << '\n';
        }
    }

    return 0;
}