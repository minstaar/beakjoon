#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    string s; cin >> s;
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'l') s[i] = 'L';
        else s[i] = 'i';
    }

    cout << s << '\n';

    return 0;
}