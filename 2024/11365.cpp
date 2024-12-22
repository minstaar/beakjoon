#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(1){
        string str;
        getline(cin, str);
        if(str == "END") break;
        reverse(str.begin(), str.end());
        cout << str << '\n';
    }

    return 0;
}