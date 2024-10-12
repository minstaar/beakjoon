#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> constructZ(string &s)
{
    int N = s.size(), l = 0, r = 0;
    vector<int> z(N);
    z[0] = N;
    for(int i=1; i<N; i++){
        if(i <= r) z[i] = min(r - i + 1, z[i-l]);
        while(i + z[i] < N && s[z[i]] == s[i+z[i]]) z[i]++;
        if(i + z[i] - 1 > r){
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin >> s;
    int N = s.size();
    auto z = constructZ(s);
    
    vector<int> cnt(N+1);
    for(int i=0; i<N; i++){
        cnt[z[i]]++;
    }
    for(int i=N; i>0; i--) cnt[i-1] += cnt[i]; 

    vector<pair<int, int>> res;
    for(int i=0; i<N; i++){
        if(z[i] == N - i){
            res.push_back({z[i], cnt[z[i]]});
        }
    }
    cout << res.size() << '\n';
    for(int i=res.size()-1; i>=0; i--){
        cout << res[i].first << ' ' << res[i].second << '\n';
    }

    return 0;
}