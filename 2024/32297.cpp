#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    string str; cin >> str;
    string s = "gori";

    if(strstr(str.c_str(), s.c_str())) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}