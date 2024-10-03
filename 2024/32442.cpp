#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, arr[110], sum;
bool dp[110][5010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum % 2){
        cout << "-1\n";
        return 0;
    }

    dp[0][0] = true;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=sum/2; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= arr[i]) dp[i][j] |= dp[i-1][j-arr[i]];
        }
    }

    if(!dp[N][sum/2]){
        cout << "-1\n";
        return 0;
    }

    int i, w = sum / 2;
    queue<int> q1, q2;
    for(i=N; i>0; i--){
        if(w >= arr[i] && dp[i-1][w-arr[i]]){
            q1.push(arr[i]);
            w -= arr[i];
        }
        else q2.push(arr[i]);
    }

    vector<int> res;
    int sum1 = 0, sum2 = 0;
    res.push_back(q1.front());
    sum1 += q1.front();
    q1.pop();
    while(!q1.empty() && !q2.empty()){
        if(sum1 <= sum2){
            res.push_back(q1.front());
            sum1 += q1.front();
            q1.pop();
        }
        else{
            res.push_back(q2.front());
            sum2 += q2.front();
            q2.pop();
        }
    }
    if(q1.empty()){
        while(!q2.empty()){
        res.push_back(q2.front());
            q2.pop();
        }
    }
    else{
        while(!q1.empty()){
            res.push_back(q1.front());
            q1.pop();
        }
    }

    for(int i=0; i<N; i++){
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;    
}