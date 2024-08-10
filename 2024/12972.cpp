#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    multiset<int, greater<int>> s;
    for(int i=0; i<N*N; i++){
        int a; cin >> a;
        s.insert(a);
    }

    vector<int> res;
    for(int i=0; i<N; i++){
        int a = *s.begin();
        for(auto x: res){
            int t = __gcd(a, x);
            s.erase(s.find(t));
            s.erase(s.find(t));
        }
        s.erase(s.find(a));
        res.push_back(a);
    }

    for(auto x: res) cout << x << ' ';
    cout << '\n';

    return 0;
}