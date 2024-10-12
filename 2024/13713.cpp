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
        while(i + z[i] < N && s[z[i]] == s[i+z[i]]){
            z[i]++;
        }
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
    reverse(s.begin(), s.end());
    auto z = constructZ(s);
    reverse(z.begin(), z.end());

    int M; cin >> M;
    while(M--){
        int i; cin >> i;
        cout << z[i-1] << '\n';
    }

    return 0;
}