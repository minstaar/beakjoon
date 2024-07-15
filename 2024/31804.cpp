#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
bool check[2][1000010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a, b; cin >> a >> b;
    queue<pair<int, pii>> que;
    que.push({a, {0, 0}});
    check[0][a] = true;
    while(!que.empty()){
        int cur = que.front().first;
        int cnt = que.front().second.first;
        int chance = que.front().second.second;
        que.pop();   
        if(cur + 1 <= b && !check[chance][cur+1]){
            check[chance][cur+1] = true;
            if(cur + 1 == b){
                cout << cnt + 1 << '\n';
                break;
            }
            que.push({cur + 1, {cnt + 1, chance}});
        }
        if(cur * 2 <= b && !check[chance][cur*2]){
            check[chance][cur*2] = true;
            if(cur * 2 == b){
                cout << cnt + 1 << '\n';
                break;
            }
            que.push({cur * 2, {cnt + 1, chance}});
        }
        if(chance == 0 && cur * 10 <= b){
            check[1][cur*10] = true;
            if(cur * 10 == b){
                cout << cnt + 1 << '\n';
                break;
            }
            que.push({cur * 10, {cnt + 1, 1}});
        }
    }

    return 0;
}