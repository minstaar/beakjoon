#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int grundy = 0;
    for(int i=0; i<N; i++){
        int t; cin >> t;
        grundy ^= t - 2;
    }
    string str; cin >> str;
    if(grundy) cout << (str == "Whiteking" ? "Whiteking" : "Blackking") << '\n';
    else cout << (str == "Whiteking" ? "Blackking" : "Whiteking") << '\n';

    return 0;
}