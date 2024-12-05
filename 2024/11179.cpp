#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    bitset<200> bit(N);
    string s = bit.to_string();
    reverse(s.begin(), s.end());
    int idx = s.size() - 1;
    while(idx >= 0 && s[idx] == '0'){
        s.pop_back();
        idx--;
    }
    bitset<200> res(s);
    cout << res.to_ulong() << '\n';

    return 0;
}