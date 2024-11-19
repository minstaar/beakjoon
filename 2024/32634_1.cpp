#include <iostream>
using namespace std;
using ll = long long;

int N, M, psum[200010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        int t, k; cin >> t >> k;
        psum[t-k+1] += 1;
        psum[t+1] -= 1;
    }

    for(int i=1; i<=N; i++) psum[i] += psum[i-1];
    
    auto check = [](int x){
        ll sum = 0;
        for(int i=1; i<=N; i++){
            sum += x - psum[i];
            if(sum < 0) return false;
        }
        return true;
    };
    
    int l = 0, r = M;
    while(l <= r){
        int m = l + r >> 1;
        if(check(m)) r = m - 1;
        else l = m + 1;
    }
    cout << l << '\n';

    return 0;
}