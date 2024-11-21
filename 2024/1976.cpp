#include <iostream>
#include <vector>
using namespace std;

struct UnionFind
{
    vector<int> parent;
    UnionFind(int n): parent(n, -1) {}
    int Find(int x){
        return parent[x] < 0 ? x : parent[x] = Find(parent[x]);
    }
    bool Union(int x, int y){
        x = Find(x);
        y = Find(y);
        if(x == y) return false;
        parent[x] += parent[y];
        parent[y] = x;
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    UnionFind UF(N+1);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int a; cin >> a;
            if(a) UF.Union(i, j);
        }
    }
    bool flag = true;
    int t; cin >> t;
    t = UF.Find(t);
    for(int i=1; i<M; i++){
        int a; cin >> a;
        if(t != UF.Find(a)) flag = false;
    }

    cout << (flag ? "YES\n" : "NO\n");

    return 0;
}