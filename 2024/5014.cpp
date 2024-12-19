#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int F, S, G, U, D; cin >> F >> S >> G >> U >> D;

    queue<pii> que;
    vector<bool> visited(F+1);
    que.push({S, 0});
    visited[S] = true;
    while(!que.empty()){
        auto [pos, cnt] = que.front();
        que.pop();
        if(pos == G){
            cout << cnt << '\n';
            return 0;
        }
        if(pos - D > 0 && !visited[pos-D]){
            visited[pos-D] = true;
            que.push({pos - D, cnt + 1});
        }
        if(pos + U <= F && !visited[pos+U]){
            visited[pos+U] = true;
            que.push({pos + U, cnt + 1});
        }
    }

    cout << "use the stairs\n";

    return 0;
}