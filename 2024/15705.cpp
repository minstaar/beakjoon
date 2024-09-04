#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> arr(110);
string str;
int N, M;
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool solve(int x, int y, int dir)
{
    int nx = x, ny = y;
    for(int i=1; i<str.length(); i++){
        nx += dx[dir], ny += dy[dir];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] != str[i]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> str;
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];

    bool flag = false;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == str[0]){
                for(int k=0; k<8; k++){
                    if(solve(i, j, k)){
                        flag = true;
                        break;
                    }
                }
            }
        }
    }
    cout << (flag ? 1 : 0) << '\n';

    return 0;   
}