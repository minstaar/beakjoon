#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

typedef vector<vector<ll>> matrix;
matrix operator * (const matrix &a, const matrix &b){
    matrix ret(a.size(), vector<ll>(b[0].size()));
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            for(int k=0; k<b[0].size(); k++){
                ret[i][k] = (ret[i][k] + a[i][j] * b[j][k]) % MOD;
            }
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    matrix g = {{0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0}};
    matrix res(8, vector<ll>(8));
    for(int i=0; i<8; i++) res[i][i] = 1;

    int K; cin >> K;
    while(K){
        if(K & 1) res = res * g;
        g = g * g;
        K >>= 1;
    }

    cout << res[0][0] << '\n';
    
    return 0;
}