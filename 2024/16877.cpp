#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

vector<int> fibo = {1, 2};
int grundy[3000010];
bitset<31> mex;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(int i=2; fibo.back()<=3e6; i++){
        fibo.push_back(fibo[i-2] + fibo[i-1]);
    }
    for(int i=1; i<=3e6; i++){
        for(auto f: fibo){
            int state = i - f;
            if(state < 0) break;
            mex[grundy[state]] = 1;
        }
        while(mex[grundy[i]]) grundy[i]++;
        mex.reset();
    }
    
    int N; cin >> N;
    int x = 0;
    for(int i=0; i<N; i++){
        int t; cin >> t;
        x ^= grundy[t];
    }
    cout << (x ? "koosaga" : "cubelover") << '\n';

    return 0;
}