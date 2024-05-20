#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, inDegree[510], cost[510], res[510];
vector<int> child[510];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> cost[i];
        res[i] = cost[i];
        while(1){
            int a; cin >> a;
            if(a == -1) break;
            child[a].push_back(i);
            inDegree[i]++;
        }
    }

    queue<int> que;
    for(int i=1; i<=N; i++){
        if(inDegree[i] == 0) que.push(i);
    }
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto next: child[cur]){
            inDegree[next]--;
            if(inDegree[next] == 0) que.push(next);
            res[next] = max(res[next], res[cur] + cost[next]);
        }
    }

    for(int i=1; i<=N; i++) cout << res[i] << '\n';

    return 0;
}