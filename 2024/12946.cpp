#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N, ans;
vector<string> arr(55);
int visited[55][55];

void dfs(int x, int y, int color)
{
    for(int i=0; i<6; i++){
        int nx = x + "001221"[i] - '1';
        int ny = y + "122100"[i] - '1';
        if(nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny] == '-') continue;
        if(visited[nx][ny] == -1){
            visited[nx][ny] = color;
            dfs(nx, ny, 1 - color);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    memset(visited, -1, sizeof(visited));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 'X' && visited[i][j] == -1){
                visited[i][j] = 0;
                dfs(i, j, 1);
                ans = 1;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == '-') continue;
            for(int k=0; k<6; k++){
                int nx = i + "001221"[k] - '1';
                int ny = j + "122100"[k] - '1';
                if(nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny] == '-') continue;
                if(visited[i][j] == visited[nx][ny]) ans = 3;
                else ans = max(ans, 2);
            }
        }
    }

    cout << ans;

    return 0;
}