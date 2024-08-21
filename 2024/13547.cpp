#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int sqrtN;

struct Query
{
    int idx, s, e;
    bool operator < (const Query &o) const{
        if(s / sqrtN != o.s / sqrtN) return s / sqrtN < o.s / sqrtN;
        return e < o.e;
    }
};

int arr[100010], cnt[1000010], ans[100010];
vector<Query> query(100010);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, Q; cin >> N;
    sqrtN = sqrt(N);
    for(int i=1; i<=N; i++) cin >> arr[i];
    cin >> Q;
    for(int i=0; i<Q; i++){
        int a, b; cin >> a >> b;
        query[i] = {i, a, b};
    }

    sort(query.begin(), query.begin() + Q);
    int s = query[0].s, e = query[0].e;
    int res = 0;
    for(int i=s; i<=e; i++){
        if(cnt[arr[i]] == 0) res++;
        cnt[arr[i]]++;
    }
    ans[query[0].idx] = res;

    for(int i=1; i<Q; i++){
        while(s < query[i].s){
            cnt[arr[s]]--;
            if(cnt[arr[s]] == 0) res--;
            s++;
        }
        while(s > query[i].s){
            s--;
            if(cnt[arr[s]] == 0) res++;
            cnt[arr[s]]++;
        }
        while(e < query[i].e){
            e++;
            if(cnt[arr[e]] == 0) res++;
            cnt[arr[e]]++;
        }
        while(e > query[i].e){
            cnt[arr[e]]--;
            if(cnt[arr[e]] == 0) res--;
            e--;
        }
        ans[query[i].idx] = res;
    }
    
    for(int i=0; i<Q; i++) cout << ans[i] << '\n';

    return 0;
}