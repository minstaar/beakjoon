#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

int N, M, psum[200010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        psum[a] = 1;
        M = max(M, a);
    }
    for(int i=1; i<=200000; i++) psum[i] += psum[i-1];

    vector<vector<bool>> dp(sqrt(M)+3, vector<bool>(M+1));
    dp[0][0] = 1;
    for(int i=0; i<=sqrt(M)+2; i++){
        for(int j=0; j<=M; j++){
            if(!dp[i][j]) continue;
            
            if(j == 0 && psum[0] == 0 || j > 0 && psum[j] - psum[j-1] == 0){
                if(j + 1 >= M){
                    cout << "YES\n";
                    return 0;
                }
                dp[i][j+1] = 1;
            }
            
            if(j + i >= M){
                cout << "YES\n";
                return 0;
            }
            else if(psum[min(j+(i+1)*2-1, M)] - psum[j+i] == 0){
                if(j + (i + 1) * 2 >= M){
                    cout << "YES\n";
                    return 0;
                }
                dp[i+1][j+(i+1)*2] = 1;
            }
        }
    }
    cout << "NO\n";

    return 0;
}