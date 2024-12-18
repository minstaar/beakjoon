#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int CCW(pll &A, pll &B, pll &C)
{
    ll op = A.first * B.second + B.first * C.second + C.first * A.second;
    op -= B.first * A.second + C.first * B.second + A.first * C.second;
    return (op > 0) - (op < 0);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<pll> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i].first >> arr[i].second;

    for(int i=0; i<3; i++){
        pll P; cin >> P.first >> P.second;
        int cnt = 0;
        for(int j=0; j<N; j++){
            pll A = arr[j];
            pll B = arr[(j+1)%N];
            pll Q = {1e9 + 1, P.second - 1};
            if(CCW(A, B, P) == 0 && min(A, B) <= P && P <= max(A, B)){
                cout << "1\n";
                cnt = -1;
                break;
            }
            int line1_2 = CCW(A, B, P) * CCW(A, B, Q);
            int line2_1 = CCW(P, Q, A) * CCW(P, Q, B);
            cnt += (line1_2 < 0 && line2_1 < 0);
        }
        if(cnt != -1) cout << (cnt % 2 ? "1\n" : "0\n");
    }

    return 0;
}