#include <iostream>
using namespace std;

int N, K;
bool arr[400010];

bool solve(int dist)
{
    int cnt = 0, idx = 0;
    while(idx < N - 1){
        int tmp = idx + dist;
        for(; tmp > idx && !arr[tmp]; tmp--);
        if(tmp == idx) return false;
        idx = tmp;
        cnt++;
    }
    return cnt <= K;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> arr[i];

    int l = 0, r = N - 1;
    while(l <= r){
        int m = l + r >> 1;
        if(solve(m)) r = m - 1;
        else l = m + 1;
    }
    cout << l << '\n';

    return 0;
}