#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int val[200010];
pii childVal[200010], childIdx[200010];
vector<pii> depth[200010];


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;

    for(int i=1; i<=N; i++){
        int v, d;
        cin >> v >> d;
        val[i] = v;
        childVal[i] = {-2e9 - 1, 2e9 + 1};
        depth[d].push_back({v, i});
    }

    if(depth[1].size() != 1){
        cout << -1 << '\n';
        return 0;
    }

    for(int i=1; i<=N; i++) sort(depth[i].begin(), depth[i].end());

    for(int i=1; i<N; i++){
        auto cur = depth[i].begin();
        auto next = depth[i+1].begin();
        while(cur != depth[i].end() && next != depth[i+1].end()){
            int curIdx = cur->second;
            int nextIdx = next->second;
            if(childIdx[curIdx].first == 0){
                int lVal = childVal[curIdx].first;
                int rVal = val[curIdx];
                if(val[nextIdx] < lVal){
                    cout << -1 << '\n';
                    return 0;
                }
                if(val[nextIdx] > rVal){
                    childIdx[curIdx].first = -1;
                    continue;
                }
                childIdx[curIdx].first = nextIdx;
                childVal[nextIdx] = {lVal, rVal};
                next++;
            }
            else{
                int lVal = val[curIdx];
                int rVal = childVal[curIdx].second;
                if(val[nextIdx] < lVal){
                    cout << -1 << '\n';
                    return 0;
                }
                if(val[nextIdx] > rVal){
                    childIdx[curIdx].second = -1;
                    cur++;
                    continue;
                }
                childIdx[curIdx].second = nextIdx;
                childVal[nextIdx] = {lVal, rVal};
                cur++, next++;
            }
        }
        if(next != depth[i+1].end()){
            cout << -1 << '\n';
            return 0;
        }
    }

    for(int i=1; i<=N; i++){
        if(childIdx[i].first == 0) cout << -1 << ' ';
        else cout << childIdx[i].first << ' ';
        if(childIdx[i].second == 0) cout << -1 << '\n';
        else cout << childIdx[i].second << '\n';
    }

    return 0;
}