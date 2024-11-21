#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s, t;
    while(cin >> s >> t){
        int idx = 0;
        for(int i=0; i<t.size(); i++){
            if(s[idx] == t[i]) idx++;
        }
        if(idx == s.size()) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}