#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, ans1, ans2;
vector<vector<char>> arr(55, vector<char>(55));
int visited1[55][55], visited2[55][55];

void dfs1(int x, int y, int color)
{
    for(int i=0; i<6; i++){
        int nx = x + "001221"[i] - '1';
        int ny = y + "122100"[i] - '1';
        if(nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny] == '-') continue;
        if(visited1[nx][ny] == -1){
            visited1[nx][ny] = color;
            dfs1(nx, ny, 1 - color);
        }
    }
}

void solve1()
{
    memset(visited1, -1, sizeof(visited1));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 'X' && visited1[i][j] == -1){
                visited1[i][j] = 0;
                dfs1(i, j, 1);
                ans1 = 1;
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
                if(visited1[i][j] == visited1[nx][ny]) ans1 = 3;
                else ans1 = max(ans1, 2);
            }
        }
    }
}


void dfs2(int x, int y)
{
    for(int i=0; i<6; i++){
        int nx = x + "001221"[i] - '1';
        int ny = y + "122100"[i] - '1';
        if(nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny] == '-') continue;
        if(!visited2[nx][ny]){
            visited2[nx][ny] = visited2[x][y] == 1 ? 2 : 1;
            dfs2(nx, ny);
        }
    }

    ans2 = max(ans2, 1);
    for(int i=0; i<6; i++){
        int nx = x + "001221"[i] - '1';
        int ny = y + "122100"[i] - '1';
        if(nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny] == '-' || !visited2[nx][ny]) continue;
        if(visited2[x][y] == visited2[nx][ny]){
            ans2 = 3;
        }
        else ans2 = max(ans2, 2);
    }
}

void solve2()
{
    memset(visited2, 0, sizeof(visited2));
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-1; j++){
            if(arr[i+1][j] == 'X' && arr[i][j+1] == 'X'){
                if(arr[i][j] == 'X' || arr[i+1][j+1] == 'X'){
                    ans2 = 3;
                    return;
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 'X' && !visited2[i][j]){
                visited2[i][j] = 1;
                dfs2(i, j);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    N = 5;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 1);
    while(ans1 == ans2){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                arr[i][j] = dis(gen) ? 'X' : '-';
            }
        }
        ans1 = 0, ans2 = 0;
        solve1();
        solve2();
    }
    cout << ans1 << ' ' << ans2 << '\n';
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }

    

    return 0;
}