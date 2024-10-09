#include <bits/stdc++.h>
using namespace std;

vector<int> constructSA(string &str)
{
    int N = str.length(), M = max(256, N) + 1;
    vector<int> sa(N), r(N*2), nr(N*2), cnt(M), idx(N);

    for(int i=0; i<N; i++) sa[i] = i, r[i] = str[i];
    for(int d=1; d<N; d<<=1){
        auto cmp = [&](int i, int j){
            return r[i] < r[j] || (r[i] == r[j] && r[i+d] < r[j+d]);
        };

        for(int i=0; i<M; i++) cnt[i] = 0;
        for(int i=0; i<N; i++) cnt[r[i+d]]++;
        for(int i=1; i<M; i++) cnt[i] += cnt[i-1];
        for(int i=N-1; i>=0; i--) idx[--cnt[r[i+d]]] = i;

        for(int i=0; i<M; i++) cnt[i] = 0;
        for(int i=0; i<N; i++) cnt[r[i]]++;
        for(int i=1; i<M; i++) cnt[i] += cnt[i-1];
        for(int i=N-1; i>=0; i--) sa[--cnt[r[idx[i]]]] = idx[i];

        nr[sa[0]] = 1;
        for(int i=1; i<N; i++) nr[sa[i]] = nr[sa[i-1]] + cmp(sa[i-1], sa[i]);
        for(int i=0; i<N; i++) r[i] = nr[i];

        if(r[sa[N-1]] == N) break;
    }

    return sa;
}

vector<int> constructLCP(string &str, vector<int> &sa)
{
    int N = str.length();
    vector<int> lcp(N), isa(N);
    for(int i=0; i<N; i++) isa[sa[i]] = i;
    for(int i=0, k=0; i<N; i++, k=max(k-1, 0)){
        if(isa[i] == 0) continue;
        for(int j=sa[isa[i]-1]; str[i+k]==str[j+k]; k++);
        lcp[isa[i]] = k;
    }
    return lcp;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    string str; cin >> str;

    auto sa = constructSA(str);
    auto lcp = constructLCP(str, sa);
    cout << *max_element(lcp.begin(), lcp.end()) << '\n';

    return 0;
}