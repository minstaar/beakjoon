#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> manacher(string &s)
{
    int N = s.size(), k = -1, r = -1;
    vector<int> p(N);
    for(int i=0; i<N; i++){
        if(i <= r) p[i] = min(r - i, p[2*k-i]);
        while(i - p[i] - 1 >= 0 && i + p[i] + 1 < N && s[i-p[i]-1] == s[i+p[i] +1]) p[i]++;
        if(i + p[i] > r){
            k = i, r = i + p[i];
        }
    }
    return p;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s = "$", t; cin >> t;
    for(auto c: t) s += c, s += "$";
    auto p = manacher(s);
    cout << *max_element(p.begin(), p.end()) << '\n';

    return 0;
}