#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Data{
    int idx, p, time;
    bool operator < (const Data &o) const{
        if(p - time == o.p - o.time) return idx > o.idx;
        return p - time < o.p - o.time;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, T; cin >> N >> T;
    priority_queue<Data> pq;
    for(int i=0; i<N; i++){
        int p; cin >> p;
        pq.push({i, p, 0});
    }

    vector<int> res(N);
    for(int i=1; i<=T; i++){
        Data cur = pq.top();
        pq.pop();
        res[cur.idx]++;
        pq.push({cur.idx, cur.p, i});
    }

    for(int i=0; i<N; i++) cout << res[i] << ' ';

    return 0;
}