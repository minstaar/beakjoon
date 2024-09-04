#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
using pii = pair<int, int>;

int N, M, sx, sy;
int visited[510][510];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> sx >> sy;
    map<pii, int> m;
    for(int i=0; i<M; i++){
        int x, y; cin >> x >> y;
        m[{x, y}] = i;
    }

    vector<int> res(M);
    memset(visited, -1, sizeof(visited));
    queue<pii> que;
    que.push({sx, sy});
    visited[sx][sy] = 0;
    while(!que.empty()){
        auto [x, y] = que.front();
        que.pop();
        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <= 0 || nx > N || ny <= 0 || ny > N || visited[nx][ny] != -1) continue;
            visited[nx][ny] = visited[x][y] + 1;
            if(m.find({nx, ny}) != m.end()){
                res[m[{nx, ny}]] = visited[nx][ny];
            }
            que.push({nx, ny});
        }
    }

    for(int i=0; i<M; i++){
        cout << res[i] << ' ';
    }

    return 0;
}