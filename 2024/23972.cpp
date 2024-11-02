#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int K, N; cin >> K >> N;

    if(N == 1){
        cout << "-1\n";
        return 0;
    }
    for(int i=K; ; i++){
        if((i - K) * N >= i){
            cout << i << '\n';
            break;
        }
    }

    return 0;
}