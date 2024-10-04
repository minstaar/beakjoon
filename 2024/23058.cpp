#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> arr(10, vector<int>(10)), tmp(10, vector<int>(10));

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    int ans = 1e9;
    for(int i=0; i<(1<<(N*2)); i++){
        tmp = arr;
        for(int j=0; j<N*2; j++){
            if((i >> j) & 1){
                if(j < N){
                    for(int k=0; k<N; k++){
                        tmp[j][k] ^= 1;
                    }
                }
                else{
                    for(int k=0; k<N; k++){
                        tmp[k][j-N] ^= 1;
                    }
                }
            }
        }
        int cnt1 = 0;
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if(tmp[j][k]) cnt1++;
            }
        }
        ans = min(ans, __builtin_popcount(i) + min(cnt1, N * N - cnt1));
    }

    cout << ans << '\n';

    return 0;
}