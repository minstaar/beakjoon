#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

int N, T, arr[110][110];
ll dist[110][110][3];

struct Data
{
    int x, y, k;
    bool operator < (const Data &o) const{
        return k < o.k;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> T;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cin >> arr[i][j];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dist[i][j][0] = dist[i][j][1] = dist[i][j][2] = 1e18;
        }
    }

    priority_queue<pair<ll, Data>> pq;
    pq.push({0, {0, 0, 0}});
    dist[0][0][0] = 0;

    while(!pq.empty()){
        auto [curDist, cur] = pq.top();
        pq.pop();
        curDist *= -1LL;
        auto[x, y, k] = cur;
        if(curDist > dist[x][y][k]) continue;
        for(int i=0; i<4; i++){
            int nx = x + "1210"[i] - '1';
            int ny = y + "2101"[i] - '1';
            int nk = (k + 1) % 3;
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(dist[nx][ny][nk] > dist[x][y][k] + T + (nk == 0 ? arr[nx][ny] : 0)){
                dist[nx][ny][nk] = dist[x][y][k] + T + (nk == 0 ? arr[nx][ny] : 0);
                pq.push({-dist[nx][ny][nk], {nx, ny, nk}});
            }
        }
    }

    cout << *min_element(dist[N-1][N-1], dist[N-1][N-1] + 3) << '\n';

    return 0;
}