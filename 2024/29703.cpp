#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N, M;
vector<string> arr(1010);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];

    int sx, sy, ex, ey;
    map<pii, int> m;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 'S') sx = i, sy = j;
            else if(arr[i][j] == 'H') ex = i, ey = j;
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M));
    queue<pair<pii, int>> que;
    que.push({{sx, sy}, 0});
    visited[sx][sy] = true;
    while(!que.empty()){
        auto [p, cost] = que.front();
        que.pop();
        if(arr[p.first][p.second] == 'F'){
            m[p] = cost;
        }
        for(int i=0; i<4; i++){
            int nx = p.first + "1210"[i] - '1';
            int ny = p.second + "2101"[i] - '1';
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visited[nx][ny] || arr[nx][ny] == 'D') continue;
            visited[nx][ny] = true;
            que.push({{nx, ny}, cost + 1});
        }
    }

    int ans = 1e9;
    visited = vector<vector<bool>>(N, vector<bool>(M));
    que.push({{ex, ey}, 0});
    visited[ex][ey] = true;
    while(!que.empty()){
        auto [p, cost] = que.front();
        que.pop();
        if(arr[p.first][p.second] == 'F'){
            if(m.find(p) != m.end()) ans = min(ans, m[p] + cost);
        }
        for(int i=0; i<4; i++){
            int nx = p.first + "1210"[i] - '1';
            int ny = p.second + "2101"[i] - '1';
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visited[nx][ny] || arr[nx][ny] == 'D') continue;
            visited[nx][ny] = true;
            que.push({{nx, ny}, cost + 1});
        }
    }

    if(ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}