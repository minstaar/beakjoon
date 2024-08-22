#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int N;
vector<int> adj[100010], parent(100010), order(100010), arr(100010);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> que;
    que.push(1);
    parent[1] = 1;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto next: adj[cur]){
            if(!parent[next]){
                parent[next] = cur;
                que.push(next);
            }
        }
    }

    bool flag = true;
    parent[1] = 0;
    order[0] = -1;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        order[arr[i]] = i;
    }
    for(int i=1; i<N; i++){
        if(order[parent[arr[i-1]]] > order[parent[arr[i]]]){
            flag = false;
            break;
        }
    }
    cout << (flag ? 1 : 0) << '\n';

    return 0;
}