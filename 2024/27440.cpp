#include <iostream>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll N; cin >> N;
    queue<ll> que;
    map<ll, int> visited;
    que.push(N);
    visited[N] = 0;
    while(!que.empty()){
        ll cur = que.front();
        que.pop();
        if(cur == 1) break;
        int cnt = visited[cur];
        if(cur % 3 == 0 && visited.find(cur / 3) == visited.end()){
            visited[cur/3] = cnt + 1;
            que.push(cur / 3);
        }
        if(cur % 2 == 0 && visited.find(cur / 2) == visited.end()){
            visited[cur/2] = cnt + 1;
            que.push(cur / 2);
        }
        if(visited.find(cur - 1) == visited.end()){
            visited[cur-1] = cnt + 1;
            que.push(cur - 1);
        }
    }
    cout << visited[1] << '\n';

    return 0;
}