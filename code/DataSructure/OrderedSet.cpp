#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set s;
//auto x = s.find_by_order(k);
//s.order_of_key(k);

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

void m_erase(ordered_multiset &OS, int val){
    int index = OS.order_of_key(val);
    ordered_multiset::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}