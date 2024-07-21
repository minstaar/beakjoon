#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<char> arr(30);
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> arr[i*5+j];
        }
    }
    int res = 0;
    for(int i=0; i<(1<<25); i++){
        if(__builtin_popcount(i) != 7) continue;
        int cntS = 0, cnt = 0;
        for(int j=0; j<25; j++){
            if((i >> j) & 1){
                queue<int> que; que.push(j);
                vector<bool> visited(30); visited[j] = true;
                if(arr[j] == 'S') cntS++;
                cnt = 1;
                while(!que.empty()){
                    int cur = que.front(); que.pop();
                    int x = cur / 5, y = cur % 5;
                    for(int k=0; k<4; k++){
                        int nx = x + "1210"[k] - '1';
                        int ny = y + "2101"[k] - '1';
                        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visited[nx*5+ny]) continue;
                        if((i >> (nx * 5 + ny)) & 1){
                            visited[nx*5+ny] = true;
                            if(arr[nx*5+ny] == 'S') cntS++;
                            cnt++;
                            que.push(nx * 5 + ny);
                        }
                    }
                }
                break;
            }
        }
        if(cnt != 7) continue;
        if(cntS >= 4){
            res++;
        }
    }
    cout << res << '\n';

    return 0;
}