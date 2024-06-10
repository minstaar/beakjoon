#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[10][10];
bool visited[10][10][10];
struct Data
{
    int y;
    int x;
    int cnt;
    int k;
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> arr[i][j];
        }
    }
    int sy, sx; cin >> sy >> sx;

    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    queue<Data> que;
    visited[0][sy][sx] = true;
    que.push({sy, sx, 0, 0});
    bool flag = false;
    while(!que.empty()){
        Data cur = que.front();
        que.pop();
        if(cur.k == 6 && arr[cur.y][cur.x] == 6){
            cout << cur.cnt << '\n';
            flag = true;
            break;
        }
        
        for(int i=0; i<4; i++){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
            if(arr[ny][nx] == -1 || visited[cur.k][ny][nx]) continue;
            visited[cur.k][ny][nx] = true;
            if(cur.k + 1 == arr[ny][nx]){
                visited[cur.k+1][ny][nx] = true;
                que.push({ny, nx, cur.cnt + 1, cur.k + 1});
            }
            else que.push({ny, nx, cur.cnt + 1, cur.k});
        }

        for(int i=0; i<4; i++){
            int ny = cur.y;
            int nx = cur.x;
            while(ny + dy[i] >= 0 && ny + dy[i] < 5 && nx + dx[i] >= 0 && nx + dx[i] < 5 && arr[ny+dy[i]][nx+dx[i]] != -1){
                ny += dy[i];
                nx += dx[i];
                if(arr[ny][nx] == 7) break;
            }
            if(visited[cur.k][ny][nx]) continue;
            visited[cur.k][ny][nx] = true;
            if(cur.k + 1 == arr[ny][nx]){
                visited[cur.k+1][ny][nx] = true;
                que.push({ny, nx, cur.cnt + 1, cur.k + 1});
            }
            else que.push({ny, nx, cur.cnt + 1, cur.k});
        }
    }
    if(!flag) cout << -1 << '\n';

    return 0;
}