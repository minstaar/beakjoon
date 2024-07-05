#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

int N, cur;
int dx[10][8] = {{2, 2, -2, -2, 1, 1, -1, -1}, {1, -1, 1, -1 ,2, -2, 2, -2}, {-1, -1, 1, 1, -2, -2, 2, 2}, {-2, 2, -2, 2, -1, 1, -1, 1},
            {1, 1, 2, 2, -1, -1, -2, -2}, {-2, -2, -1, -1, 2, 2, 1, 1}, {1, 1, -2, -2, -1, -1, 2, 2}, {2, 2, -1, -1, -2, -2, 1, 1},
            {-1, 1, -2, 2, -1, 1, -2, 2}, {2, -2, 1, -1, 2, -2, 1, -1}};;
int dy[10][8] = {{1, -1, 1, -1, 2, -2, 2, -2}, {2, 2, -2, -2, 1, 1, -1, -1}, {-2, 2, -2, 2, -1, 1, -1, 1}, {-1, -1, 1, 1, -2, -2, 2, 2},
            {-2, 2, -1, 1, -2, 2, -1, 1}, {1, -1, 2, -2, 1, -1, 2, -2}, {2, -2, 1, -1, 2, -2, 1, -1}, {-1, 1, -2, 2, -1, 1, -2, 2},
            {-2, 2, -1, 1, 2, -2, 1, -1}, {-1, 1, -2, 2, 1, -1, 2, -2}};
bool visited[670][670];
vector<pii> res;

int check(int x, int y)
{
    int cnt = 0;
    for(int i=0; i<8; i++){
        int nx = x + dx[cur][i];
        int ny = y + dy[cur][i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;
        cnt++;
    }
    return cnt;
}

bool tour(int x, int y)
{
    int cx = N / 2, cy = N / 2;
    visited[x][y] = true;
    res.push_back({x, y});
    for(int i=1; i<N*N; i++){
        int val = 9, tx, ty;
        bool flag = false;
        for(int j=0; j<8; j++){
            int nx = x + dx[cur][j];
            int ny = y + dy[cur][j];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;
            int t = check(nx, ny);
            if(val > t){
                val = t;
                tx = nx, ty = ny;
                flag = true;
            }
            else if(val == t){
                if(abs(cx - tx) + abs(cy - ty) < abs(cx - nx) + abs(cy - ny)){
                    tx = nx, ty = ny;
                }
            }
        }
        if(!flag) return false;
        x = tx, y = ty;
        visited[x][y] = true;
        res.push_back({x, y});
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    int sx, sy; cin >> sx >> sy;
    bool flag = false;
    for(cur = 0; cur < 10; cur++){
        memset(visited, false, sizeof(visited));
        res.clear();
        if(tour(sx - 1, sy - 1)){
            flag = true;
            break;
        }
    }
    if(flag){
        for(auto x: res){
            cout << x.first + 1 << ' ' << x.second + 1 << '\n';
        }
    }
    else cout << "-1 -1" << '\n';

    return 0;
}