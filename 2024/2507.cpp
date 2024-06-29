#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[10010];
int l[10010], r[10010];
int dir1[110][110], dir2[110][110];
bool visit[10010], arr[110][110];

bool dfs(int a)
{
    if(visit[a]) return false;
    visit[a] = true;
    for(auto b: adj[a]){
        if(r[b] == -1 || !visit[r[b]] && dfs(r[b])){
            l[a] = b, r[b] = a;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    for(int i=0; i<M; i++){
        int y, x; cin >> y >> x;
        y--, x--;
        arr[y][x] = true;
    }
    int cnt1 = 0, cnt2 = 0;
    int y, x;
    for(int i=0; i<N*2-1; i++){
        if(i < N) y = i, x = 0;
        else y = N - 1, x = i - N + 1;
        while(y >= 0 && y < N && x >= 0 && x < N){
            if(arr[y][x]) cnt1++;
            else dir1[y][x] = cnt1;
            y--, x++; 
        }
        cnt1++;
    }
    for(int i=0; i<N*2-1; i++){
        if(i < N) y = i, x = N - 1;
        else y = N - 1, x = 2 * (N - 1) - i;
        while(y >= 0 && y < N && x >= 0 && x < N){
            if(arr[y][x]) cnt2++;
            else dir2[y][x] = cnt2;
            y--, x--;
        }
        cnt2++;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!arr[i][j]){
                adj[dir1[i][j]].push_back(dir2[i][j]);
            }
        }
    }

    int match = 0;
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    for(int i=0; i<cnt1; i++){
        if(l[i] == -1){
            memset(visit, false, sizeof(visit));
            if(dfs(i)) match++;
        }
    }
    cout << match << '\n';

    return 0;
}