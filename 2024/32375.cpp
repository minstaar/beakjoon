#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N, K, arr[200010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> arr[i];
    
    sort(arr, arr + N);
    multiset<int> s;
    for(int i=0; i<N; i++){
        if(arr[i] < K) s.insert(arr[i]);
        else break;
    }

    int res = N - s.size();
    while(s.size() >= 2){
        auto it = prev(s.end());
        int cur = *it;
        s.erase(it);
        auto it2 = s.lower_bound(K - cur);
        if(it2 == s.end()) break;
        else{
            res++;
            s.erase(it2);
        }
    }
    if(res == 0) cout << "-1\n";
    else cout << res << '\n';

    return 0;
}