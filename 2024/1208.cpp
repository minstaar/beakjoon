#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long n, k, ans;
vector<long long> arr(45);
map<long long, long long> cnt;

void dfs(int d, int p, long long sum)
{
    if(d == 0 && p == n/2){
        cnt[sum]++;
        return;
    }
    else if(d == 1 && p == n){
        auto iter = cnt.find(k - sum);
        if(iter != cnt.end()){
            ans += iter -> second;
        }
        return;
    }
    dfs(d, p + 1, sum);
    dfs(d, p + 1, sum + arr[p]);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>arr[i];

    dfs(0, 0, 0);
    dfs(1, n/2, 0);

    if(k == 0) ans--;
    cout<<ans<<'\n';

    return 0; 
}