#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N), index(N);
    map<int, int> m;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        m[arr[i]] = i;
    }
    for(int i=0; i<N; i++){
        int a; cin >> a;
        index[i] = m[a];
    }
    
    long long ans = 0;
    indexed_set s;
    s.insert(index[0]);
    for(int i=1; i<N; i++){
        int pos = s.order_of_key(index[i]);
        if(pos != s.size()) ans += s.size() - pos;
        s.insert(index[i]);
    }

    cout << ans << '\n';
    return 0;
}