#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, a, b; cin >> N >> a >> b;
    if(N >= a + b){
        int res = 0;
        for(int i=0; i<a+b; i++){
            res += pow(2, N - 1 - i);
        }
        cout << res << '\n';
    }
    else{
        int res = 0;
        for(int i=0; i<N; i++){
            res += pow(2, N - 1 - i);
        }
        for(int i=0; i<a+b-N; i++){
            res -= pow(2, i);
        }
        cout << res << '\n';
    }

    return 0;
}