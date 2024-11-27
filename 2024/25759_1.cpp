#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> dp(101, -1);
    for(int i=0; i<N; i++){
        int x; cin >> x;
        if(i == 0){
            dp[x] = 0;
            continue;
        }
        for(int j=1; j<=100; j++){
            if(dp[j] != -1) dp[x] = max(dp[x], dp[j] + (x - j) * (x - j));
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}