#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long n, k, ans;
vector<long long> arr(40);
map<long long, long long> cnt;

void dfs(int s, int e, int p, long long sum)
{
    if(s == 0 && p == n/2){
        cnt[sum]++;
        return;
    }
    else if(s == n/2 && p == n){
        auto iter = cnt.find(k - sum);
        if(iter != cnt.end()){
            ans += iter -> second;
        }
        return;
    }
    dfs(s, e, p + 1, sum);
    dfs(s, e, p + 1, sum + arr[p]);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>arr[i];

    dfs(0, n/2, 0, 0);
    dfs(n/2, n, n/2, 0);

    if(k == 0) ans--;
    cout<<ans<<'\n';

    return 0; 
}