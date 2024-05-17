#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

struct UnionFind
{
    int parent[200010];
    void init(int N)
    {
        for(int i=1; i<=N; i++){
            parent[i] = i;
        }
    }
    int Find(int x)
    {
        return parent[x] == x ? x : parent[x] = Find(parent[x]);
    }
    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);
        if(x == y) return;
        parent[y] = x;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, Q; cin >> N >> Q;
    vector<int> adj(N+1);
    vector<vector<int>> query(N+Q-1, vector<int>(3));
    UnionFind UF; UF.init(N);
    stack<string> ans;
    for(int i=2; i<=N; i++){
        cin >> adj[i];
    }
    Q += N - 1;
    for(int i=0; i<Q; i++){
        cin >> query[i][0] >> query[i][1];
        if(query[i][0]) cin >> query[i][2];
    }

    for(int i=Q-1; i>=0; i--){
        if(query[i][0] == 0){
            UF.Union(query[i][1], adj[query[i][1]]);
        }
        else{
            int u = query[i][1];
            int v = query[i][2];
            if(UF.Find(u) == UF.Find(v)){
                ans.push("YES");
            }
            else ans.push("NO");
        }
    }

    while(!ans.empty()){
        cout << ans.top() << '\n';
        ans.pop();
    }
    return 0;
}