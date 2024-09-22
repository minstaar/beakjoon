#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    if(N == 1 && M == 2){
        cout << "NO\n";
        return 0;
    }

    int pv = 0;
    vector<pii> res(3 * M + 20);
    for(int i=1; i<3*N; i++){
        res[pv++] = {i, i + 1};
    }
    res[pv++] = {3 * N, 1};

    int id = 1;
    while(pv < 3 * M){
        res[pv++] = {id + 1, id + 4};
        res[pv++] = {id + 2, id + 5};    
        res[pv++] = {id, id + 3};

        res[pv++] = {id, id + 2};
        res[pv++] = {id, id + 4};
        res[pv++] = {id + 2, id + 4};

        res[pv++] = {id + 1, id + 3};
        res[pv++] = {id + 3, id + 5};
        res[pv++] = {id + 1, id + 5};

        id += 6;
    }

    cout << "YES\n";
    for(int i=0; i<3*M; i++){
        cout << res[i].first << ' ' << res[i].second << '\n';
    }

    return 0;
}