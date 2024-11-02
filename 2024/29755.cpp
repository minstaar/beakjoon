#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<int> B(N);
    vector<pii> S(M);

    for(int i=0; i<N; i++) cin >> B[i];
    for(int i=0; i<M; i++) cin >> S[i].first >> S[i].second;

    sort(B.begin(), B.end());
    sort(S.begin(), S.end());

    int ans = 0;
    for(int i=0; i<M; i++){
        int idx = lower_bound(B.begin(), B.end(), S[i].first) - B.begin();
        if(idx != 0 && S[i].first - B[idx-1] < B[idx] - S[i].first || idx == N) idx--;
        ans = max(ans, abs(S[i].first - B[idx]) * S[i].second);
    }

    cout << ans << '\n';

    return 0;
}