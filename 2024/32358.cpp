#include <iostream>
#include <set>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    multiset<int> s;
    int pos = 0;
    ll res = 0;
    while(N--){
        int op; cin >> op;
        if(op == 1){
            int x; cin >> x;
            s.insert(x);
        }
        else{
                while(!s.empty()){
                auto it = s.lower_bound(pos);
                if(it == s.end()) it--;
                else if(it != s.begin()){
                    if(abs(*prev(it) - pos) <= abs(*it - pos)) it--;
                }
                res += abs(*it - pos);
                pos = *it;
                s.erase(it);
            }
        }
    }
    cout << res << '\n';

    return 0;
}