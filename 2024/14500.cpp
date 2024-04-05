#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin>>n>>m;
    vector<vector<int>> arr(n+10, vector<int>(m+10));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }

    int ans = 0;

    //i shape + monomino
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int t = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            ans = max(ans, t + max({arr[i-1][j], arr[i-1][j+1], arr[i-1][j+2], arr[i][j+3], arr[i+1][j], arr[i+1][j+1], arr[i+1][j+2]}));
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int t = arr[i][j] + arr[i+1][j] + arr[i+2][j];
            ans = max(ans, t + max({arr[i][j+1], arr[i+1][j+1], arr[i+2][j+1], arr[i+3][j], arr[i+2][j-1], arr[i+1][j-1], arr[i][j-1]}));
        }
    }

    //tetrominoes s&z shape, o shape
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int t1 = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1];
            int t2 = arr[i][j] + arr[i+1][j] + arr[i+1][j-1] + arr[i+2][j-1];
            int t3 = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2];
            int t4 = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j-1];
            int t5 = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];
            ans = max({ans, t1, t2, t3, t4, t5});
        }
    }

    cout<<ans;

    return 0;
}
