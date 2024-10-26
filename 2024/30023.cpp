#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int N;
map<char, char> nxt;

int solve(string s)
{
    int cnt = 0;
    for(int i=1; i<=N-3; i++){
        while(s[i-1] != s[i]){
            s[i] = nxt[s[i]], s[i+1] = nxt[s[i+1]], s[i+2] = nxt[s[i+2]];
            cnt++;
        }
    }
    if(s[0] == s[N-1] && s[N-1] == s[N-2]) return cnt;
    else return 1e9;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    string s; cin >> s;
    
    nxt['R'] = 'G', nxt['G'] = 'B', nxt['B'] = 'R';
    
    int ans = 1e9;
    for(int i=0; i<3; i++){
        ans = min(ans, solve(s) + i);
        s[0] = nxt[s[0]], s[1] = nxt[s[1]], s[2] = nxt[s[2]];
    }
    if(ans == 1e9) cout << "-1\n";
    else cout << ans << '\n';

    return 0;
}