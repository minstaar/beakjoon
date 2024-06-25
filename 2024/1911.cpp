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
    for(int i=0; i<N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());

    int res = 0;
    int start, end = 0;
    for(int i=0; i<N; i++){
        start = max(end, arr[i].first);
        if(start >= arr[i].second){
            end = start;
            continue;
        }
        int tmp = (arr[i].second - start) / L;
        if((arr[i].second - start) % L) tmp++;
        res += tmp;
        end = start + tmp * L;
    }
    cout << res << '\n';

    return 0;
}