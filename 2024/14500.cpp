#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin>>n>>m;
    vector<vector<int>> arr(n+5, vector<int>(n+5));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int t = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            ans = t + max({arr[i-1][j], arr[i-1][j+1], arr[i-1][j+2], arr[i][j+3], arr[i+1][j], arr[i+1][j+1], arr[i+1][j+2]});
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int t = arr[i][j] + arr[i+1][j] + arr[i+2][j];
            ans = t + max({arr[i][j+1], arr[i+1][j+1], arr[i+2][j+1], arr[i][j+3], arr[i+1][j], arr[i+1][j+1], arr[i+1][j+2]});
        }
    }

    return 0;
}
