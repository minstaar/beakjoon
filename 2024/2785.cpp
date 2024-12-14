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

    sort(arr.begin(), arr.end());
    int cnt = 0, need = N - 1, ans = 0;
    for(int i=0; i<N; i++){
        if(arr[i] >= need){
            ans = cnt + min(arr[i], need);
            break;
        }
        else{
            need -= arr[i] + 1;
            cnt += arr[i];
        }
    }
    cout << ans << '\n';

    return 0;
}