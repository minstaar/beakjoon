#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string str; cin >> str;
    int a = 0, b = 0, i = 0;
    for(; i<str.length(); i++){
        if(str[i] == ':') break;
        a = a * 10 + str[i] - '0';
    }
    for(i++; i<str.length(); i++){
        b = b * 10 + str[i] - '0';
    }
    int gcd = __gcd(a, b);
    cout << a / gcd << ':' << b / gcd << '\n';

    return 0;
}