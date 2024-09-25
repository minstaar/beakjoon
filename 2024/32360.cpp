#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, K, C;
vector<vector<char>> arr(110, vector<char>(110));
int visited[110][110][110];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K >> C;
    int sx, sy, ex, ey;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'S'){
                sx = i, sy = j;
            }
            if(arr[i][j] == 'E'){
                ex = i, ey = j;
            }
        }
    }

    memset(visited, -1, sizeof(visited));
    queue<tuple<int, int, int>> que;
    que.push(make_tuple(sx, sy, 0));
    visited[sx][sy][0] = 0;
    int ans = 1e9;
    while(!que.empty()){
        auto [x, y, stat] = que.front();
        que.pop();
        if(arr[x][y] == 'E'){
            ans = min(ans, visited[x][y][stat]);
            continue;
        }
        if(arr[x][y] == 'H' && stat != 0){
            if(visited[x][y][max(0, stat-K)] == -1){
                visited[x][y][max(0, stat-K)] = visited[x][y][stat] + 1;
                que.push(make_tuple(x, y, max(0, stat - K)));
            }

        }
        for(int i=0; i<4; i++){
            int nx = x + "1210"[i] - '1';
            int ny = y + "2101"[i] - '1';
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == 'S' || arr[nx][ny] == '#') continue;
            if(arr[nx][ny] != 'H' && stat + C < 100 && visited[nx][ny][stat+C] == -1){
                visited[nx][ny][stat+C] = visited[x][y][stat] + 1;
                que.push(make_tuple(nx, ny, stat + C));
            }
            else if(arr[nx][ny] == 'H' && visited[nx][ny][max(0, stat-K)] == -1){
                visited[nx][ny][max(0, stat-K)] = visited[x][y][stat] + 1;
                que.push(make_tuple(nx, ny, max(0, stat - K)));
            }
        }
    }

    if(ans == 1e9) cout << "-1\n";
    else cout << ans << '\n';

    return 0;
}