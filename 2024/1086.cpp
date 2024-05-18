#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
int N, K;
string str[20];
ll dp[1<<15][110];
int remainA[20], remainTen[55], len[20];

ll solve(int state, int num)
{
    if(state == (1 << N) - 1) return num % K == 0;
    ll& res = dp[state][num];
    if(res != -1) return res;
    res = 0;
    for(int i=0; i<N; i++){
        if(state & (1 << i)) continue;
        int nextNum = num * remainTen[len[i]] + remainA[i];
        nextNum %= K;
        res += solve(state | (1 << i), nextNum);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> str[i];
        len[i] = str[i].length();
    }
    cin >> K;
    for(int i=0; i<N; i++){
        int tmp = 0;
        for(int j=0; j<len[i]; j++){
            tmp *= 10;
            tmp += str[i][j] - '0';
            tmp %= K;
        }
        remainA[i] = tmp;
    }
    remainTen[0] = 1 % K;
    for(int i=1; i<55; i++){
        remainTen[i] = remainTen[i-1] * 10 % K;
    }

    memset(dp, -1, sizeof(dp));
    ll p = solve(0, 0), q = 1;
    if(p == 0){
        cout << "0/1" << '\n';
    }
    else{
        for(int i=1; i<=N; i++) q *= i;
        ll g = __gcd(p, q);
        cout << p/g << '/' << q/g << '\n';
    }

    return 0;
}