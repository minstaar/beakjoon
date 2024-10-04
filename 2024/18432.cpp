#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, K;
int psum[200010][3];
string str;

int solve(int start, int type)
{
    int l = start, r = N;
    while(l <= r){
        int m = l + r >> 1;
        int cnt = psum[m][type] - psum[start-1][type];
        if(cnt >= K){
            r = m - 1;
        }
        else l = m + 1;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    cin >> str;
    for(int i=1; i<=N; i++){
        for(int j=0; j<3; j++){
            psum[i][j] = psum[i-1][j];
        }
        if(str[i-1] == 'J') psum[i][0]++;
        else if(str[i-1] == 'O') psum[i][1]++;
        else psum[i][2]++;
    }

    int ans = 1e9;
    for(int i=1; i<=N-K*3+1; i++){
        if(str[i-1] != 'J') continue;
        int a = solve(i, 0);
        int b = solve(a + 1, 1);
        int c = solve(b + 1, 2);
        if(c <= N) ans = min(ans, c - i + 1 - (3 * K));
    }
    if(ans == 1e9) cout << "-1\n";
    else cout << ans << '\n';

    return 0;
}