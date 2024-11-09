#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin >> s;
    string a, b;
    int idx = 0;
    bool flag = true;
    for(; idx<s.size(); idx++){
        if(s[idx] == '+') break;
        if(s[idx] < '0' || s[idx] > '9') flag = false;
        a.push_back(s[idx]);
    }
    for(idx++; idx<s.size(); idx++){
        if(s[idx] < '0' && s[idx] > '9') flag = false;
        b.push_back(s[idx]);
    }

    if(flag && a.size() > 0 && a == b && a[0] != '0') cout << "CUTE\n";
    else cout << "No Money\n";

    return 0;
}