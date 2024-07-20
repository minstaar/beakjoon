#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int N;
map<pii, int> m;
vector<pii> arr(50010);
vector<int> adj[50010], color(50010);

int bfs(int s)
{
    int color1 = 0, color2 = 0;
    queue<int> que;
    que.push(s);
    color1 = color[s] = 1;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto next: adj[cur]){
            if(!color[next]){
                color[next] = color[cur] * -1;
                color[next] == 1 ? color1++ : color2++;
                que.push(next);
            }
        }
    }
    return min(color1, color2);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i].first >> arr[i].second;
        m[arr[i]] = i;
    }
    for(int i=0; i<N; i++){
        for(int j=-5; j<=5; j++){
            for(int k=-5; k<=5; k++){
                if(j == 0 && k == 0 || j * j + k * k > 25) continue;
                int nx = arr[i].first + j, ny = arr[i].second + k;
                if(m.find({nx, ny}) != m.end()) adj[i].push_back(m[{nx, ny}]);
            }
        }
    }

    int res = 0;
    for(int i=0; i<N; i++){
        if(!color[i]) res += bfs(i);
    }

    cout << res << '\n';

    return 0;
}