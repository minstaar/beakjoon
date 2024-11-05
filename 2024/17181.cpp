#include <iostream>
#include <algorithm>
using namespace std;

int N, M, arr[55][55], ans;
int visited[55][55][3];

void dfs(int x, int y, int type, int cnt) // type : 초성 - 0, 중성 - 1, 종성 - 2
{
    if(visited[x][y][type] <= cnt) return;
    visited[x][y][type] = cnt;

    if(x == N - 1 && y == M - 1){
        if(type != 0) ans = min(ans, cnt);
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x + "1210"[i] - '1';
        int ny = y + "2101"[i] - '1';
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        int ntype = (arr[nx][ny] < 14 ? 0 : 1);
        if(type == 0 && ntype == 1){ // 초성 -> 중성
            dfs(nx, ny, ntype, cnt + 1);
        }
        if(type == 1 && ntype == 0){
            dfs(nx, ny, 2, cnt); // 중성 -> 초성  
            dfs(nx, ny, 0, cnt); // 중성 -> 종성
        }
        if(type == 2 && ntype == 0){ // 종성 -> 초성
            dfs(nx, ny, ntype, cnt);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    ans = 1e9;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            visited[i][j][0] = visited[i][j][1] = visited[i][j][2] = 1e9;
        }
    }
    if(arr[0][0] < 14) dfs(0, 0, 0, 0);

    if(ans == 1e9) cout << "BAD\n";
    else cout << ans << '\n';

    return 0;
}