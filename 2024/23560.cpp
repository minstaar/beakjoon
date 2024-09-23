#include <iostream>
#include <cstring>
using namespace std;

int N, arr[50], dp[50][50];

int solve(int l, int r, int state)
{
    if(state == N * 3){
        if(arr[l] == 1) return 1;
        else return 0;
    }
    int &ret = dp[l][r];
    if(ret != -1) return ret;
    ret = 0;
    if((state % 3) == 2){
        if(arr[l] == 0) ret += solve(l + 1, r, state + 1);
        if(arr[r] == 0) ret += solve(l, r - 1, state + 1);
    }
    else{
        if(arr[l] == 1) ret += solve(l + 1, r, state + 1);
        if(arr[r] == 1) ret += solve(l, r - 1, state + 1);
    }
    
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=N*3; i+=3){
        arr[i] = true;
        arr[i+1] = false;
        arr[i+2] = true;
    }
    
    cout << solve(1, N * 3, 1) << '\n';

    return 0;
}