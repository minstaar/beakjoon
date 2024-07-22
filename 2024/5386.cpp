#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N, K; cin >> N >> K;
        if(K % 2){
            if(N % 2 == 0) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else{
            if(N % (K + 1) == K) cout << K << '\n';
            else if(N % (K + 1) % 2 == 0) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
    }

    return 0;
}