#include <iostream>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
using ll = long long;

int N;
const ll mx = pow(2LL, 60);
set<ll> s;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        ll a; cin >> a;
        s.insert(a);
    }
    if(s.find(1) != s.end()){
        cout << "0\n";
        return 0;
    }

    queue<ll> que;
    que.push(1);
    int cnt = 1;
    while(!que.empty()){
        ll cur = que.front();
        que.pop();
        if(s.find(cur * 2) == s.end()){
            que.push(cur * 2);
            cnt++;
            if(cur * 2 >= mx || cnt >= N){
                cout << "-1\n";
                return 0;
            }
        }
        if(s.find(cur * 2 + 1) == s.end()){
            que.push(cur * 2 + 1);
            cnt++;
            if(cur * 2 >= mx || cnt >= N){
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}