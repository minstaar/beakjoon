#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPi(string p)
{
    int m = p.length(), j=0;
    vector<int> pi(m);
    for(int i=1; i<m; i++){
        while(j > 0 && p[i] != p[j]) j = pi[j-1];
        if(p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}

vector<int> KMP(string s, string p)
{
    vector<int> res;
    int n = s.length(), m = p.length(), j = 0;
    auto pi = getPi(p);
    for(int i=0; i<n; i++){
        while(j > 0 && s[i] != p[j]) j = pi[j-1];
        if(s[i] == p[j]){
            if(j == m - 1){
                res.push_back(i - m + 1);
                j = pi[j];
            }
            else j++;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        string p, s; cin >> p >> s;
        auto res = KMP(s, p);
        cout << res.size() << '\n';
    }

    return 0;
}