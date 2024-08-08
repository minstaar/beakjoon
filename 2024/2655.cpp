#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data
{
    int area, height, weight, idx;
    bool operator < (const Data &o) const{
        if(area == o.area) return weight < o.weight;
        return area < o.area;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<Data> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i].area >> arr[i].height >> arr[i].weight;
        arr[i].idx = i + 1;
    }
    sort(arr.begin(), arr.end());

    vector<int> dp(N), cnt(N), prev(N, -1);
    int mx = -1, idx;
    for(int i=0; i<N; i++){
        dp[i] = arr[i].height;
        cnt[i] = 1;
        for(int j=i-1; j>=0; j--){
            if(arr[i].weight > arr[j].weight && dp[i] < dp[j] + arr[i].height){
                dp[i] = dp[j] + arr[i].height;
                cnt[i] = cnt[j] + 1;
                prev[i] = j;
            }
        }
        if(mx < dp[i]){
            mx = dp[i];
            idx = i;
        }
    }

    cout << cnt[idx] << '\n';
    vector<int> res;
    for(int i=idx; i!=-1; i=prev[i]) res.push_back(arr[i].idx);
    reverse(res.begin(), res.end());
    for(auto x: res) cout << x << '\n';
    
    return 0;
}