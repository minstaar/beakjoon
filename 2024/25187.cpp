#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
    vector<int> parent, sum;

    UnionFind(int n): parent(n+1, -1), sum(n+1) {}

    int Find(int x){
        return parent[x] < 0 ? x : parent[x] = Find(parent[x]);
    }

    bool Union(int x, int y){
        x = Find(x), y = Find(y);
        if(x != y){
            parent[x] += parent[y];
            parent[y] = x;
            sum[x] += sum[y];
            return true;
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, Q; cin >> N >> M >> Q;
    UnionFind UF(N+1);
    for(int i=1; i<=N; i++) cin >> UF.sum[i];
    for(int i=0; i<M; i++){
        int x, y; cin >> x >> y;
        UF.Union(x, y);
    }
    for(int i=0; i<Q; i++){
        int a; cin >> a;
        a = UF.Find(a);
        cout << (-UF.parent[a] / 2 < UF.sum[a]) << '\n';
    }
    
    return 0;
}