#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, arr[1010], dp[1010], pre[1010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    
    int mx = 0, s;
    for(int i=0; i<N; i++){
        dp[i] = 1;
        pre[i] = -1;
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
        if(mx < dp[i]){
            mx = dp[i];
            s = i;
        }
    }

    vector<int> res;
    for(int i=s; i != -1; i = pre[i]) res.push_back(arr[i]);
    reverse(res.begin(), res.end());
    
    cout << res.size() << '\n';
    for(auto x: res) cout << x << ' ';
    cout << '\n';

    return 0;
}