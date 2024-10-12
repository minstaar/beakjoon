#include <bits/stdc++.h>
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