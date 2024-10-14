#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N, arr[2230][2230];
vector<vector<int>> visited(2230, vector<int>(2230, 1e9));

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    queue<pii> que;
    que.push({0, 0});
    visited[0][0] = 0;
    while(!que.empty()){
        auto [x, y] = que.front();
        que.pop();
        if(x + 1 < N){
            int diff = arr[x][y] > arr[x+1][y] ? 0 : arr[x+1][y] - arr[x][y] + 1;
            if(visited[x+1][y] > visited[x][y] + diff){
                visited[x+1][y] = visited[x][y] + diff;
                que.push({x + 1, y});
            }
        }
        if(y + 1 < N){
            int diff = arr[x][y] > arr[x][y+1] ? 0 : arr[x][y+1] - arr[x][y] + 1;
            if(visited[x][y+1] > visited[x][y] + diff){
                visited[x][y+1] = visited[x][y] + diff;
                que.push({x, y + 1});
            }
        }
    }
    cout << visited[N-1][N-1] << '\n';

    return 0;
}