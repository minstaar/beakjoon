#include <bits/stdc++.h>
using namespace std;

template<typename cost_t> struct Hungarian{
    int n, m; 
    cost_t INF = numeric_limits<cost_t>::max() / 2;
    vector<vector<cost_t>> mat;

    Hungarian(int n, int m): n(n), m(m), mat(n+1, vector<cost_t>(m+1, INF)) {}

    void addEdge(int s, int e, cost_t x){
        mat[s][e] = min(mat[s][e], x);
    }

    pair<cost_t, vector<int>> run(){
        vector<cost_t> u(n+1), v(m+1), minv(m+1);
        vector<int> p(m+1), way(m+1), used(m+1);
        for(int i=1; i<=n; i++){
            fill(minv.begin(), minv.end(), INF);
            fill(used.begin(), used.end(), 0);
            p[0] = i;
            int j0 = 0;
            do{
                int i0 = p[j0], j1;
                cost_t delta = INF;
                used[j0] = 1;
                for(int j=1; j<=m; j++){
                    if(!used[j]){
                        cost_t cur = mat[i0][j] - u[i0] - v[j];
                        if(cur < minv[j]){
                            minv[j] = cur;
                            way[j] = j0;
                        }
                        if(minv[j] < delta){
                            delta = minv[j];
                            j1 = j;
                        }
                    }
                }
                for(int j=0; j<=m; j++){
                    if(used[j]){
                        u[p[j]] += delta;
                        v[j] -= delta;
                    }
                    else minv[j] -= delta;
                }
                j0 = j1;
            }while(p[j0] != 0);

            do{
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            }while(j0 != 0);
        }
        vector<int> assign(n+1);
        for(int i=1; i<=m; i++) assign[p[i]] = i;

        return {-v[0], assign};
    }
};