#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int N, K, P;
int heap[200010], upVal, downVal;
bool flag;

void dfs(int idx)
{
    heap[idx] = downVal++;
    if(downVal > N + 1){
        flag = true;
        return;
    }
    if((idx << 1) <= N) dfs(idx << 1);
    if((idx << 1 | 1) <= N) dfs(idx << 1 | 1);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K >> P;

    upVal = 1, downVal = K;
    dfs(P);
    int idx = P;
    stack<int> st;
    while(idx >>= 1) st.push(idx);
    while(!st.empty()){
        heap[st.top()] = upVal++;
        st.pop();
        if(upVal > K){
            flag = true;
            break;
        }
    }

    if(flag) cout << -1 << '\n';
    else{
        queue<int> que;
        for(int i=upVal; i<K; i++) que.push(i);
        for(int i=downVal; i<=N; i++) que.push(i);
        for(int i=1; i<=N; i++){
            if(heap[i]) cout << heap[i] << ' ';
            else{
                cout << que.front() << ' ';
                que.pop();
            }
        }

    }

    return 0;
}