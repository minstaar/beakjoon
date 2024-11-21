#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    bool flag = true;
    string t; cin >> t;
    for(int i=1; i<N; i++){
        string s; cin >> s;
        if(s[0] != t[0]) flag = false;
    }
    cout << flag << '\n';

    return 0;
}