#include <bits/stdc++.h>
using namespace std;

vector<int> getPi(string &p)
{
    int N = p.size(), j = 0;
    vector<int> pi(N);
    for(int i=1; i<N; i++){
        while(j && p[i] != p[j]) j = pi[j-1];
        if(p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}

vector<int> KMP(string &s, string &p)
{
    vector<int> res;
    int N = s.size(), M = p.size(), j = 0;
    auto pi = getPi(p);
    for(int i=0; i<N; i++){
        while(j > 0 && s[i] != p[j]) j = pi[j-1];
        if(s[i] == p[j]){
            if(j == M - 1){
                res.push_back(i - M + 1);
                j = pi[j];
            }
            else j++;
        }
    }
    return res;
}
