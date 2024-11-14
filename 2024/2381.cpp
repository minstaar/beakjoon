#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<pii> arr(N);
    for(int i=0; i<N; i++){
        int x, y; cin >> x >> y;
        arr[i] = {x + y, x - y};
    }
    
    int mxX = -INF, mnX = INF;
    int mxY = -INF, mnY = INF;
    for(int i=0; i<N; i++){
        mxX = max(mxX, arr[i].first);
        mnX = min(mnX, arr[i].first);
        mxY = max(mxY, arr[i].second);
        mnY = min(mnY, arr[i].second);
    }
    cout << max(mxX - mnX, mxY - mnY) << '\n';

    return 0;
}