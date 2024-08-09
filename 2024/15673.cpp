#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int INF = 1e9;
int N, arr[100010];
int dpmx[100010][2], dpmn[100010][2], dpmx2[100010][2], dpmn2[100010][2];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];

    dpmx[0][0] = dpmx[0][1] = -INF;
    dpmn[0][0] = dpmn[0][1] = INF;
    for(int i=1; i<=N; i++){
        dpmx[i][0] = max(dpmx[i-1][0] + arr[i], arr[i]);
        dpmx[i][1] = max(dpmx[i-1][0], dpmx[i-1][1]);
        dpmn[i][0] = min(dpmn[i-1][0] + arr[i], arr[i]);
        dpmn[i][1] = min(dpmn[i-1][0], dpmn[i-1][1]);
    }
    dpmx2[N+1][0] = dpmx2[N+1][1] = -INF;
    dpmn2[N+1][0] = dpmn2[N+1][1] = INF;
    for(int i=N; i>=1; i--){
        dpmx2[i][0] = max(dpmx2[i+1][0] + arr[i], arr[i]);
        dpmx2[i][1] = max(dpmx2[i+1][0], dpmx2[i+1][1]);
        dpmn2[i][0] = min(dpmn2[i+1][0] + arr[i], arr[i]);
        dpmn2[i][1] = min(dpmn2[i+1][0], dpmn2[i+1][1]);
    }

    ll res = -INF;
    for(int i=1; i<N; i++){
        res = max(res, 1LL * max(dpmx[i][0], dpmx[i][1]) * max(dpmx2[i+1][0], dpmx2[i+1][1]));
        res = max(res, 1LL * min(dpmn[i][0], dpmn[i][1]) * min(dpmn2[i+1][0], dpmn2[i+1][1]));
    }
    cout << res << '\n';

    return 0;
}