#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int N, M, x, y;
vector<vector<char>> arr(60, vector<char>(60));

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> x >> y;
    queue<pii> que;
    que.push({x, y});
    arr[x][y] = 'N';
    while(!que.empty()){
        auto [cx, cy] = que.front();
        que.pop();
        for(int i=0; i<4; i++){
            int nx = cx + "1210"[i] - '1';
            int ny = cy + "2101"[i] - '1';
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] != 0) continue;
            arr[nx][ny] = "WNES"[i];
            que.push({nx, ny});
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}