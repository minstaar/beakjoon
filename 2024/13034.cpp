#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> dp(1010);
    dp[0] = dp[1] = 0;
    for(int i=2; i<=N; i++){
        vector<int> mex(1010);
        for(int j=0; j<=(i-2)/2; j++){
            mex[dp[j] ^ dp[(i-2) - j]] |= 1;
        }
        for(int j=0; j<=N; j++){
            if(!mex[j]){
                dp[i] = j;
                break;
            }
        }
    }
    cout << (dp[N] ? 1 : 2) << '\n';

    return 0;
}