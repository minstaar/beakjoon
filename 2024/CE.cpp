#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, T; cin >> N >> T;
    set<int> s;
    
    for(int i=1; i<=T; i++){
        if(T % i == 0) s.insert(i);
    }

    int ans = 0;
    while(N--){
        int a; cin >> a;
        auto it = s.lower_bound(a);
        if(it != s.begin()){
            if(abs(*prev(it) - a) < abs(*it - a)) it = prev(it);
        }
        ans += abs(*it - a);
    }
    cout << ans << '\n';

    return 0;
}