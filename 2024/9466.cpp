#include <iostream>
#include <vector>
using namespace std;

int order, cycle;
vector<int> arr, discovered;
vector<bool> finished;

void dfs(int node)
{
    discovered[node] = order++;
    if(discovered[arr[node]] == -1){
        dfs(arr[node]);
    }
    else if(!finished[arr[node]]){
        cycle += discovered[node] - discovered[arr[node]] + 1;
    }
    finished[node] = true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        arr = vector<int>(n+1);
        discovered = vector<int>(n+1, -1);
        finished = vector<bool>(n+1);
        for(int i=1; i<=n; i++) cin>>arr[i];
        order = cycle = 0;
        for(int i=1; i<=n; i++){
            if(!finished[i]) dfs(i);
            finished[i] = true;
        }
        cout<<n - cycle<<'\n';
    }

    return 0;
}