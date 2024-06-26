#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    const int INF = 1e9;
    int N, M; cin >> M >> N;
    vector<string> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];
    
    vector<vector<int>> dist(N, vector<int>(M, INF));
    deque<pii> dq;
    dq.push_back({0, 0});
    dist[0][0] = 0;
    while(!dq.empty()){
        auto [y, x] = dq.front();
        dq.pop_front();
        for(int i=0; i<4; i++){
            int ny = y + "1210"[i] - '1';
            int nx = x + "2101"[i] - '1';
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(dist[ny][nx] > dist[y][x] + arr[ny][nx] - '0'){
                dist[ny][nx] = dist[y][x] + arr[ny][nx] - '0';
                if(arr[ny][nx] - '0') dq.push_back({ny, nx});
                else dq.push_front({ny, nx});
            }
        }
    }
    cout << dist[N-1][M-1] << '\n';

    return 0;
}