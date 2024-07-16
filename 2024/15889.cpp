#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> dist(N), weight(N);
    vector<bool> check(N);
    for(int i=0; i<N; i++) cin >> dist[i];
    for(int i=0; i<N-1; i++) cin >> weight[i];

    check[0] = true;
    bool flag = true;
    for(int i=0; i<N-1; i++){
        if(!check[i]){
            flag = false;
            break;
        }
        int idx = upper_bound(dist.begin(), dist.end(), dist[i] + weight[i]) - dist.begin() - 1;
        for(int j=i; j<=idx; j++) check[j] = true;
    }
    cout << (flag && check[N-1] ? "권병장님, 중대장님이 찾으십니다" : "엄마 나 전역 늦어질 것 같아") << '\n';

    return 0;
}