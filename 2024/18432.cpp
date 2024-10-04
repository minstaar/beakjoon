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
        else if(str[i-1] == '0') psum[i][1]++;
        else psum[i][2]++;
    }

    int ans = 0;
}