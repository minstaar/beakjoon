#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C, arr[35];
long long ans;
vector<long long> vec[2];

void solve(int k, int s, int e, int cur, long long sum)
{
    if(sum > C) return;
    if(cur >= e){
        vec[k].push_back(sum);
        return;
    }

    solve(k, s, e, cur + 1, sum);
    solve(k, s, e, cur + 1, sum + arr[cur]);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> C;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    solve(0, 0, N/2, 0, 0);
    solve(1, N/2, N, N/2, 0);

    sort(vec[0].begin(), vec[0].end());
    for(int i=0; i<vec[1].size(); i++){
        ans += upper_bound(vec[0].begin(), vec[0].end(), C - vec[1][i]) - vec[0].begin();
    }

    cout << ans << '\n';

    return 0;
}