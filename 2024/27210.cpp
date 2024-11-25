#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];

    int cnt1 = 0, ans1 = 0;
    for(int i=0; i<N; i++){
        if(arr[i] == 1) cnt1++;
        else{
            cnt1 = max(cnt1 - 1, 0);
        }
        ans1 = max(ans1, cnt1);
    }

    int cnt2 = 0, ans2 = 0;
    for(int i=0; i<N; i++){
        if(arr[i] == 2) cnt2++;
        else{
            cnt2 = max(cnt2 - 1, 0);
        }
        ans2 = max(ans2, cnt2);
    }

    cout << max(ans1, ans2) << '\n';

    return 0;
}