#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

    int L; string s; cin >> L >> s;
    auto z = constructZ(s);
    int k = 0;
    for(int i=1; i<L; i++){
        if(i + z[i] == L) k = max(k, z[i]);
    }
    cout << L - k << '\n';

    return 0;
}