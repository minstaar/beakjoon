#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;
using pii = pair<int, int>;

struct Edge
{
    int u, v;
    bool type;
};

set<int> obj;
vector<int> root, adj[400010]; //ref_id, to, state
map<int, Edge> edges;
map<int, int> objID; int pv;
vector<bool> visited(400010);

int bfs(bool type)
{
    visited.assign(pv + 10, 0);
    queue<int> que;
    int ret = 0;
    for(auto a: root){
        que.push(a);
        visited[a] = true;
        ret++;
    }

    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto next: adj[cur]){
            if(edges.find(next) == edges.end()) continue;
            auto [u, v, r_type] = edges[next];
            if(obj.find(v) == obj.end() || visited[v] || type && r_type == false) continue;
            visited[v] = true;
            que.push(v);
            ret++;
        }
    }

    for(int i=0; i<pv; i++){
        if(!visited[i]){
            obj.erase(i);
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int O, E; cin >> O >> E;
    for(int i=0; i<O; i++){
        int a; string s; cin >> a >> s;
        objID[a] = pv;
        obj.insert(pv);
        if(s == "ROOT") root.push_back(pv);
        pv++;
    }

    while(E--){
        string op; cin >> op;
        if(op == "MADE"){
            int a; string s; cin >> a >> s;
            objID[a] = pv;
            obj.insert(pv);
            if(s == "ROOT") root.push_back(pv);
            pv++;
        }
        else if(op == "ADD"){
            int i, u, v; string s; cin >> i >> u >> s >> v;
            u = objID[u], v = objID[v];
            if(s == "=>") edges[i] = {u, v, true};
            else edges[i] = {u, v, false};
            adj[u].push_back(i);
        }
        else if(op == "REMOVE"){
            int i; cin >> i;
            edges.erase(i);
        }
        else if(op == "m"){
            cout << bfs(0) << '\n';
        }
        else{
            cout << bfs(1) << '\n';
        }
    }

    return 0;
}