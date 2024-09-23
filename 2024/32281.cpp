#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int N;
bool arr[200010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    N; cin >> N;
    string s; cin >> s;
    ll res = 0, cnt = 0;
    for(int i=0; i<s.length(); i++){
        arr[i] = s[i] == '1';
        if(arr[i]) cnt++;
        else{
            res += cnt * (cnt + 1) / 2;
            cnt = 0;
        }
    }
    res += cnt * (cnt + 1) / 2;
    cout << res << '\n';
    
    return 0;
}