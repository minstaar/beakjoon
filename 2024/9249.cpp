#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define all(v) v.begin(), v.end()
using namespace std;

vector<int> constructSA(string &s)
{
    int N = s.size(), M = max(256, N) + 1;
    vector<int> sa(N), r(N*2), nr(N*2), cnt(M), idx(N);
    for(int i=0; i<N; i++) sa[i] = i, r[i] = s[i];
    for(int d=1; d<N; d<<=1){
        auto cmp = [&](int i, int j){
            return r[i] < r[j] || (r[i] == r[j] && r[i+d] < r[j+d]);
        };

        for(int i=0; i<M; i++) cnt[i] = 0;
        for(int i=0; i<N; i++) cnt[r[i+d]]++;
        for(int i=0; i<M; i++) cnt[i] += cnt[i-1];
        for(int i=N-1; i>=0; i--) idx[--cnt[r[i+d]]] = i;

        for(int i=0; i<M; i++) cnt[i] = 0;
        for(int i=0; i<N; i++) cnt[r[i]]++;
        for(int i=0; i<M; i++) cnt[i] += cnt[i-1];
        for(int i=N-1; i>=0; i--) sa[--cnt[r[idx[i]]]] = idx[i];

        nr[sa[0]] = 1;
        for(int i=1; i<N; i++) nr[sa[i]] = nr[sa[i-1]] + cmp(sa[i-1], sa[i]);
        for(int i=0; i<N; i++) r[i] = nr[i];

        if(r[sa[N-1]] == N) break;
    }
    
    return sa;
}

vector<int> constructLCP(string &s, vector<int> &sa)
{
    int N = s.size();
    vector<int> lcp(N), isa(N);
    for(int i=0; i<N; i++) isa[sa[i]] = i;
    for(int i=0, k=0; i<N; i++, k=max(k-1, 0)) if(isa[i]){
        for(int j=sa[isa[i]-1]; s[i+k]==s[j+k]; k++);
        lcp[isa[i]] = k;
    }
    return lcp;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s, t; cin >> s >> t;
    string str = s + '$' + t;
    auto sa = constructSA(str);
    auto lcp = constructLCP(str, sa);

    int mx = 0, idx = 0;
    int sn = s.size();
    for(int i=1; i<str.size(); i++){
        if((sa[i-1] < sn) ^ (sa[i] < sn)){
            if(lcp[i] > mx){
                mx = lcp[i];
                idx = i;
            }
        }
    }

    cout << mx << '\n' << str.substr(sa[idx], lcp[idx]) << '\n';

    return 0;
}