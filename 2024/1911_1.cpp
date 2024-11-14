#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, L; cin >> N >> L;
    vector<pii> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());

    int cnt = 0, prev = -1;
    for(int i=0; i<N; i++){
        if(prev >= arr[i].second) continue;
        if(prev >= arr[i].first){
            int t = (arr[i].second - prev - 1) / L;
            if((arr[i].second - prev - 1) % L) t++;
            prev += t * L;
            cnt += t;
        }
        else{
            int t = (arr[i].second - arr[i].first) / L;
            if((arr[i].second - arr[i].first) % L) t++;
            prev = arr[i].first + t * L - 1;
            cnt += t;
        }
    }
    cout << cnt << '\n';

    return 0;
}