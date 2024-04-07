#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    vector<int> arr(n);
    vector<vector<int>> dp(n, vector<int>(n));
    for(int i=0; i<n; i++) cin>>arr[i];

    for(int i=0; i<n; i++){
        dp[i][i] = 1;
        int s = i - 1, e = i + 1;
        for(int s = i-1, e = i+1; s >= 0 && e < n; s--, e++){
            if(arr[s] != arr[e]) break;
            dp[s][e] = 1;
        }

        if(arr[i] == arr[i+1]){
            dp[i][i+1] = 1;
            for(int s = i - 1, e = i + 2; s >= 0 && e < n; s--, e++){
                if(arr[s] != arr[e]) break;
                dp[s][e] = 1;
            }
        }
    }

    int query; cin>>query;
    while(query--){
        int a, b; cin>>a>>b;
        dp[a-1][b-1] ? cout<<1<<'\n' : cout<<'0'<<'\n';
    }

    return 0;
}
