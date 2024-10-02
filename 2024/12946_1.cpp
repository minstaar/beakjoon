#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N, ans;
vector<string> arr(55);
int visited[55][55];

void dfs(int x, int y)
{
    for(int i=0; i<6; i++){
        int nx = x + "001221"[i] - '1';
        int ny = y + "122100"[i] - '1';
        if(nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny] == '-') continue;
        if(!visited[nx][ny]){
            visited[nx][ny] = visited[x][y] == 1 ? 2 : 1;
            dfs(nx, ny);
        }
    }

    ans = max(ans, 1);
    for(int i=0; i<6; i++){
        int nx = x + "001221"[i] - '1';
        int ny = y + "122100"[i] - '1';
        if(nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny] == '-' || !visited[nx][ny]) continue;
        if(visited[x][y] == visited[nx][ny]){
            ans = 3;
        }
        else ans = max(ans, 2);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-1; j++){
            if(arr[i+1][j] == 'X' && arr[i][j+1] == 'X'){
                if(arr[i][j] == 'X' || arr[i+1][j+1] == 'X'){
                    cout << 3;
                    return 0;
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 'X' && !visited[i][j]){
                visited[i][j] = 1;
                dfs(i, j);
            }
        }
    }

    cout << ans;

    return 0;
}