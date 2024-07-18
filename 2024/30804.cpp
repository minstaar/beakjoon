#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int N, arr[200010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    int res = 2;
    int left = 0, right = 1;
    set<int> s; s.insert(arr[left]), s.insert(arr[right]);
    map<int, int> m; m[arr[left]]++, m[arr[right]]++;
    while(left <= N - 2 && right <= N - 1){
        while(s.size() <= 2){
            right++;
            if(right >= N) break;
            s.insert(arr[right]);
            m[arr[right]]++;
            if(s.size() <= 2) res = max(res, right - left + 1);
        }
        while(s.size() > 2){
            if(--m[arr[left]] == 0) s.erase(arr[left]);
            left++;
        }
    }

    if(N == 1) cout << 1 << '\n';
    else cout << res << '\n';

    return 0;
}