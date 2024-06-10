#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
vector<string> arr(110);
vector<vector<bool>> visited(110, vector<bool>(110));
int N, M, blue, white;

void bfs(int y, int x)
{
    visited[y][x] = true;
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    int cnt = 1;
    queue<pii> que;
    que.push({y, x});
    while(!que.empty()){
        pii cur = que.front();
        que.pop();
        for(int i=0; i<4; i++){
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(!visited[ny][nx] && arr[ny][nx] == arr[y][x]){
                visited[ny][nx] = true;
                cnt++;
                que.push({ny, nx});
            }
        }
    }
    arr[y][x] == 'W' ? white += cnt * cnt : blue += cnt * cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j]){
                bfs(i, j);
            }
        }
    }
    cout << white << ' ' << blue << '\n';

    return 0;
}