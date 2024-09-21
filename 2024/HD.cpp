#include <iostream>
#include <string>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        string str; cin >> str;
        ll res = 1;
        bool flag = false;
        for(int i=0; i<str.length(); i++){
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
                flag = true;
                int j;
                for(j=i+1; j<str.length() && (str[j] != 'a' && str[j] != 'e' && str[j] != 'i' && str[j] != 'o' && str[j] != 'u'); j++);
                if(j == str.length()) break;
                res = (res * (j - i)) % MOD;
                i = j - 1;
            }
        }
        if(!flag) cout << "-1\n";
        else cout << res << '\n';
    }

    return 0;
}