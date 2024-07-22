#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MOD = 1000000007;

int arr[1024], dp[1024][1024][2];
int N, K;

int solve(int num, int bits, int carry) {
    if (bits < 0) return 0;
    if (num < 0) return (!bits && !carry) || (bits == 1 && carry);
    int& ret = dp[num][bits][carry];
    if (ret != -1) return ret;
    ret = 0;

    ret = (ret + solve(num - 1, bits - (arr[num] ^ carry), arr[num] & carry)) % MOD;
    ret = (ret + solve(num - 1, bits - (arr[num] ^ (1 ^ carry)), arr[num] + 1 + carry > 1)) % MOD;
    return ret;
}

int main()
{
    string str;
    cin >> N >> K >> str;
    for(int i=0; i<N; i++){
        arr[i] = str[i] - '0';
    }
    memset(dp, -1, sizeof(dp));
    
    cout << solve(N - 1, K, 0) << '\n';
    
    return 0;
}
