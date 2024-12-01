#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for(int k=1; k<=T; k++){
        int N; cin >> N;
        vector<int> arr(N);
        for(int i=0; i<N; i++) cin >> arr[i];
        int res = 0;
        for(int i=0; i<N; i++){
            auto it = min_element(arr.begin(), arr.end());
            int idx = it - arr.begin();
            res += min(idx, (int)arr.size() - idx - 1);
            arr.erase(it);
        }
        cout << "Case #" << k << ": " << res << '\n';
    }

    return 0;
}