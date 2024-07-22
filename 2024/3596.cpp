#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

int grundy[2010];

int solve(int n)
{
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    int &ret = grundy[n];
    if(ret != -1) return ret;
    ret = 0;
    bitset<110> mex;
    int idx = n - 3;
    for(int i=0; i<3 && idx>=0; i++, idx--) mex[solve(idx)] = true;
    for(; idx>=1; idx--){
        mex[solve(idx)^solve(n-5-idx)] = true;
    }
    while(mex[ret]) ret++;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    memset(grundy, -1, sizeof(grundy));
    cout << (solve(N) ? 1 : 2) << '\n';

    return 0;
}