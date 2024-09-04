#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;



int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    set<string> s;
    s.insert("i");
    s.insert("pa");
    s.insert("te");
    s.insert("ni");
    s.insert("niti");
    s.insert("a");
    s.insert("ali");
    s.insert("nego");
    s.insert("no");
    s.insert("ili");

    string str, tmp, res;
    getline(cin, str);
    stringstream stream(str);
    while(stream >> tmp){
        if(s.find(tmp) == s.end() || res.empty()) res.push_back(tmp[0] - 'a' + 'A');
    }

    cout << res << '\n';

    return 0;
}