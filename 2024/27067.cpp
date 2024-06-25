#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<vector<int>> arr(3, vector<int>(N));
    map<int, int> mp[3];
    for(int i=0; i<3; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            mp[i][arr[i][j]] = j;
        }
    }

    vector<int> adj[3010], inDegree(3010);
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            int u = arr[0][i];
            int v = arr[0][j];
            if(mp[1][u] > mp[1][v] && mp[2][u] > mp[2][v]){
                adj[v].push_back(u);
                inDegree[u]++;
            }
            else{
                adj[u].push_back(v);
                inDegree[v]++;
            }
        }
    }

    queue<int> que;
    for(int i=0; i<N; i++){
        if(!inDegree[arr[0][i]]) que.push(arr[0][i]);
    }
    while(!que.empty()){
        int cur = que.front(); que.pop();
        cout << cur << ' ';
        for(auto next: adj[cur]){
            inDegree[next]--;
            if(!inDegree[next]) que.push(next);
        }
    }

    return 0;
}