#include <iostream>
#include <bitset>
#include <cstring>
using namespace std;

int grundy[5010];

int solve(int n)
{
    if(n == 0 || n == 1) return 0;
    int &ret = grundy[n];
    if(ret != -1) return ret;
    ret = 0;
    bitset<10> mex;
    for(int i=0; i<n/2; i++){
        mex[solve(i)^solve(n-i-2)] = true;
    }
    while(mex[ret]) ret++;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    memset(grundy, -1, sizeof(grundy));
    while(T--){
        int N; cin >> N;
        cout << (solve(N) ? "First" : "Second") << '\n';
    }

    return 0;
}