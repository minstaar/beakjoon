#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M, arr[110][110], visited[110][110];

bool solve(int y, int x, int dir)
{
    if(visited[y][x] & (1 << dir)) return true;
    visited[y][x] |= (1 << dir);
    int ny = y + ("1210"[dir] - '1') * arr[y][x];
    int nx = x + ("2101"[dir] - '1') * arr[y][x];
    if(ny < 0 || ny >= N || nx < 0 || nx >= M) return false;
    return solve(ny, nx, (dir + 1) % 4);
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
    vector<int> res;
    for(int i=0; i<N; i++){
        memset(visited, 0, sizeof(visited));
        if(solve(i, 0, 0)) res.push_back(i + 1);
    }
    cout << res.size() << '\n';
    for(auto x: res) cout << x << ' ';

    return 0;
}