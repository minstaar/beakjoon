#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        string str; cin >> str;
        if(!next_permutation(str.begin(), str.end())){
            cout << "BIGGEST\n";
        }
        else cout << str << '\n';
    }

    return 0;
}