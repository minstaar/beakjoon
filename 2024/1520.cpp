#include <iostream>
#include <cstring>
using namespace std;

int M, N;
int arr[510][510], dp[510][510];

int solve(int x, int y)
{
    if(x == M - 1 && y == N - 1) return 1;
    int &ret = dp[x][y];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=0; i<4; i++){
        int nx = x + "1210"[i] - '1';
        int ny = y + "2101"[i] - '1';
        if(nx < 0 || nx >= M || ny < 0 || ny >= N || arr[x][y] <= arr[nx][ny]) continue;
        ret += solve(nx, ny);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M >> N;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++) cin >> arr[i][j];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';

    return 0;
}