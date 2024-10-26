#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

const double EPS = 1e-9;
int N, P;
double dp[55][55][55];
vector<int> arr[4];

double solve(int i, int j, int k, double val)
{
    if(i + j + k >= N) return val;

    double &ret = dp[i][j][k];
    if(ret != -1) return ret;
    ret = val;

    if(i < arr[1].size() && val * 0.01 - arr[1][i] > EPS){
        ret = min(ret, solve(i + 1, j, k, val * 0.99) + arr[1][i]);
    }
    
    if(j < arr[2].size() && val * 0.02 - arr[2][j] > EPS){
        ret = min(ret, solve(i, j + 1, k, val * 0.98) + arr[2][j]);
    }
    
    if(k < arr[3].size() && val * 0.03 - arr[3][k] > EPS){
        ret = min(ret, solve(i, j, k + 1, val * 0.97) + arr[3][k]);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> P;
    for(int i=0; i<N; i++){
        int c, p; cin >> c >> p;
        arr[p].push_back(c);
    }
    for(int i=1; i<=3; i++) sort(arr[i].begin(), arr[i].end());
    for(int i=0; i<=50; i++){
        for(int j=0; j<=50; j++){
            for(int k=0; k<=50; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    cout << fixed << setprecision(6) << solve(0, 0, 0, P) << '\n';

    return 0;
}