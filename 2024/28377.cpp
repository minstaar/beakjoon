#include <iostream>
#include <set>
using namespace std;

int N, pos[200010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> pos[i];

    set<int> s;
    for(int i=0; i<N-1; i++){
        for(int j=pos[i]+1; j<pos[i+1]; j++) s.insert(j);
    }
    s.insert(pos[N-1] + 1);

    int Q; cin >> Q;
    while(Q--){
        int idx; cin >> idx;
        idx--;
        auto it = s.lower_bound(pos[idx]);
        int next = *it;
        cout << next << '\n';
        if(it == prev(s.end())) s.insert(next + 1);
        s.erase(next);
        s.insert(pos[idx]);
        pos[idx] = next;
    }

    return 0;
}