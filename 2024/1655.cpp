#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N; cin >> N;
    ordered_set s;

    for(int i=0; i<N; i++){
        int x; cin >> x;
        s.insert(x);
        cout << *s.find_by_order(i / 2) << '\n';
    }

    return 0;
}