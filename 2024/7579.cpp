#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin>>n>>m;
    int sum = 0;
    vector<int> memory(n+1), cost(n+1);
    for(int i=1; i<=n; i++){
        cin>>memory[i];
    }
    for(int i=1; i<=n; i++){
        cin>>cost[i];
        sum += cost[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(sum+1));
    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j - cost[i] < 0) dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + memory[i]);
            }
        }
    }  
    
    for(int i=0; i<=sum; i++){
        if(dp[n][i] >= m){
            cout<<i;
            break;
        }
    }

    return 0;
}
