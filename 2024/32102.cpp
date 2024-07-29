#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int N, M;
vector<pair<int, char>> color(3);
vector<int> used(3);
vector<vector<int>> arr(2010, vector<int>(2010));

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> color[0].first >> color[1].first >> color[2].first;
    color[0].second = 'R', color[1].second = 'G', color[2].second = 'B';
    sort(color.begin(), color.end(), greater<>());

    int cnt1, cnt2, cnt3_1, cnt3_2;
    if(N * M % 2){
        cnt1 = (N * M + 1) / 2;
        cnt2 = N * M / 2;
        cnt3_1 = cnt1 - color[0].first;
        cnt3_2 = cnt2 - color[1].first;
    }
    else{
        cnt1 = cnt2 = N * M / 2;
        cnt3_1 = cnt1 - color[0].first;
        cnt3_2 = cnt2 - color[1].first;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if((i + j) % 2 == 0) arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(cnt3_1 > 0 && (i + j) % 2 == 0){
                arr[i][j] = 2;
                cnt3_1--;
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(cnt3_2 > 0 && (i + j) % 2 != 0){
                bool flag = true;
                for(int k=0; k<4; k++){
                    int x = i + "1210"[k] - '1';
                    int y = j + "2101"[k] - '1';
                    if(x < 0 || x >= N || y < 0 || y >= M) continue;
                    if(arr[x][y] == 2){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    arr[i][j] = 2;
                    cnt3_2--;
                }
            }
        }
    }

    bool flag = true;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(i != N - 1 && arr[i][j] == arr[i+1][j] || j != M - 1 && arr[i][j] == arr[i][j+1]){
                flag = false;
            }
            used[arr[i][j]]++;
        }
    }
    if(!flag || color[0].first != used[0] || color[1].first != used[1] || color[2].first != used[2]) cout << "NO\n";
    else{
        cout << "YES\n";
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cout << color[arr[i][j]].second;
            }
            cout << '\n';
        }
    }

    return 0;
}