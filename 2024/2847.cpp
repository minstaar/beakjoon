#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N);
    vector<pii> sorted(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
        sorted[i] = {arr[i], i};
    }

    sort(sorted.begin(), sorted.end(), [](pii &A, pii &B){
        if(A.first == B.first) return A.second > B.second;
        return A.first < B.first;
    });

    int idx = 0, res = 0;
    for(auto [nextVal, nextIdx]: sorted){
        if(idx > nextIdx) continue;
        while(idx < N - 1){
            res += arr[idx] - (nextVal - (nextIdx - idx));
            idx++;
            if(idx > nextIdx) break;
        }
    }
    cout << res << '\n';

    return 0;
}