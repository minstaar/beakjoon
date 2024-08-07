#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s1, s2; cin >> s1 >> s2;
    if(strstr(s1.c_str(), s2.c_str()) == NULL) cout << 0 << '\n';
    else cout << 1 << '\n';;

    return 0;
}