#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> arr;
vector<vector<int>> table;

void dp(int s, int e)
{
    int m = 987654321;
    for(int i=s; i<e; i++){
        if(table[s][i] == 0 && s != i) dp(s, i);
        if(table[i+1][e] == 0 && i+1 != e) dp(i+1, e);
        m = min(m, table[s][i] + table[i+1][e] + arr[s].first * arr[i].second * arr[e].second);
    }
    table[s][e] = m;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    arr = vector<pair<int, int>>(n);
    table = vector<vector<int>>(n, vector<int>(n));
    for(int i=0; i<n; i++) cin>>arr[i].first>>arr[i].second;
    dp(0, n-1);
    cout<<table[0][n-1];

    return 0;
}
