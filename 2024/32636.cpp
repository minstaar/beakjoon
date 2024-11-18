#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N, M;
int visited[510][510];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    int sx, sy;
    queue<pair<pii, int>> que;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char a; cin >> a;
            if(a == 'G'){
                que.push({{i, j}, 0});
                visited[i][j] = 2;
            }
            else if(a == 'S'){
                sx = i, sy = j;
            }
            else if(a == '#'){
                visited[i][j] = -1;
            }
        }
    }

    int ans = -1;
    while(!que.empty()){
        auto [x, y] = que.front().first;
        int d = que.front().second;
        que.pop();
        if(x == sx && y == sy){
            ans = d;
            break;
        }
        for(int i=0; i<4; i++){
            int nx = x + "1210"[i] - '1';
            int ny = y + "2101"[i] - '1';
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visited[nx][ny] == -1 || visited[nx][ny] == 2) continue;
            if(visited[nx][ny] == 1){
                visited[nx][ny]++;
                que.push({{nx, ny}, d + 1});
            }
            else visited[nx][ny]++;
        }
    }

    cout << ans << '\n';

    return 0;
}