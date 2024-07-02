#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    queue<int> que;
    for(int i=1; i<=N; i++) que.push(i);
    while(que.size() > 1){
        int t = que.front();
        for(int i=0; i<K; i++){
            if(!que.empty()) que.pop();
        }
        que.push(t);
    }
    cout << que.front() << '\n';

    return 0;
}