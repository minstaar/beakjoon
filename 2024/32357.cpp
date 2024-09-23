#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
    int l = 0, r = s.length() - 1;
    while(l < r){
        if(s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int cnt = 0;
    for(int i=0; i<N; i++){
        string s; cin >> s;
        if(isPalindrome(s)) cnt++;
    }
    cout << cnt * (cnt - 1) << '\n';

    return 0;
}