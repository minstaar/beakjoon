#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;

struct Data{
    int sx, sy, ex, ey;
    ll h;
    int id;
    bool operator > (const Data &o)const{
        if(h == o.h){
            return id > o.id;
        }
        return h > o.h;
    }
};

set<Data, greater<Data>> s;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int Lx, Ly, N; cin >> Lx >> Ly >> N;
    ll ans = 0;
    for(int k=0; k<N; k++){
        int lx, ly, lz, px, py; cin >> lx >> ly >> lz >> px >> py;
        ll mx = 0;
        for(auto cur: s){
            if(px + lx - 1 >= cur.sx && px <= cur.ex && py + ly - 1 >= cur.sy && py <= cur.ey){
                mx = cur.h;
                break;
            }
        }
        ans = max(ans, mx + lz);
        s.insert({px, py, px + lx - 1, py + ly - 1, mx + lz, k});
    }
    cout << ans << '\n';

    return 0;
}