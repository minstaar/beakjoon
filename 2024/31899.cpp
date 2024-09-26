#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '0') cnt0++;
        else cnt1++;
    }
    if(cnt0 == 0) cout << "1\n";
    else if(cnt1 == 0) cout << "0\n";
    else{
        int len = s.length();
        if(s[0] == '0'){
            if(s[len-1] == '0') cout << "010\n";
            else cout << "01\n";
        }
        else{
            if(s[len-1] == '1') cout << "101\n";
            else cout << "10\n";
        }
    }

    return 0;
}