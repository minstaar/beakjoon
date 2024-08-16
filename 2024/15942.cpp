#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, P;
int heap[200010], downVal;
bool flag = true;

void dfs(int idx)
{
    heap[idx] = downVal++;
    if(downVal > N){
        flag = true;
        return;
    }
    if((idx << 1) <= N) dfs(idx << 1);
    if((idx << 1 | 1) <= N) dfs(idx << 1 | 1);
}

void insert(int idx)
{
    
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K >> P;

    dfs(P);
    int idx = P, upVal = K - 1;
    while(idx >>= 1){
        heap[idx] = upVal--;
        if(upVal == 0){
            flag = true;
            break;
        }
    }

    if(flag) cout << -1 << '\n';
    else{
        for(int i=1; i<=N; i++){
            if(heap[i]) continue;
            insert(i);
        }
    }

    return 0;
}