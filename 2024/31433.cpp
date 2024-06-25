#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string str; cin >> str;
    string tg = "KSA";
    int idx, ans = 1e9;
    for(int k=0; k<3; k++){
        int tmp = 0;
        idx = k;
        for(int i=0; i<str.length(); i++){
            if(str[i] == tg[idx]){
                idx = (idx + 1) % 3;
            }
            else{
                tmp++;
            }
        }
        if(tmp >= k) ans = min(ans, tmp * 2);
        else{
            ans = min(ans, 2 * k);
        }
    }
    cout << ans << '\n';

    return 0;
}