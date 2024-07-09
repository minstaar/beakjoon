#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    queue<int> que;
    deque<int> cmp;
    for(int i=0; i<N; i++){
        int t; cin >> t;
        que.push(t);
    }
    int cnt = 0;
    while(!que.empty() || !cmp.empty()){
        while(!que.empty() && cmp.size() < K){
            if(que.front() == 1) cmp.push_front(1);
            else cmp.push_back(2);
            que.pop();
        }
        if(cmp.front() != cmp.back()){
            cmp.pop_front();
            cmp.pop_back();
        }
        else cmp.pop_front();
        cnt++;
    }
    cout << cnt << '\n';

    return 0;
}