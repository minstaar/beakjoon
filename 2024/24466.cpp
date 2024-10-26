#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
using namespace std;
using ll = long long;

int N, M;
vector<pair<int, ll>> adj[110];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<ll> prev(N);
    prev[0] = 1;
    for(int i=0; i<9; i++){
        vector<ll> prob(N);
        for(int j=0; j<N; j++){
            for(auto [next, p]: adj[j]){
                prob[next] += prev[j] * p;
            }
        }
        for(int j=0; j<N; j++) prev[j] = prob[j];
    }
    
    ll val = *max_element(prev.begin(), prev.end());
    for(int i=0; i<N; i++){
        if(prev[i] == val) cout << i << ' ';
    }
    cout << '\n';
    if(val == 1e18){
        cout << fixed << setprecision(18) << 1.0 << '\n';
    }
    else{
        stack<int> res;
        while(val > 0){
            res.push(val % 10);
            val /= 10;
        }
        cout << "0.";
        for(int i=1; i<=18-res.size(); i++) cout << 0;
        while(!res.empty()){
            cout << res.top();
            res.pop();
        }
    }
    return 0;
}