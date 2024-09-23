#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr;
    int pv1, pv2;

    for(int i=0; i<N+1; i++){
        string a, b; cin >> a >> b;
        int tmp = ((a[0] - '0') * 10 + (a[1] - '0')) * 60 + (a[3] - '0') * 10 + a[4] - '0';
        if(b == "student") arr.push_back(tmp);
        else pv1 = tmp;
    }
    string s; cin >> s;
    pv2 = ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + s[4] - '0';
    
    sort(arr.begin(), arr.end());
    int ans;
    if(pv1 <= pv2) ans = arr.end() - lower_bound(arr.begin(), arr.end(), pv2);
    else ans = arr.end() - lower_bound(arr.begin(), arr.end(), pv1);
    cout << ans << '\n';

    return 0;
}