#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        string str; cin >> str;
        int ans = 0, len = str.length();
        for(int i=0; i<=len-3; i++){
            if(str[i] == 'W' && str[i+1] == 'O' && str[i+2] == 'W') ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}