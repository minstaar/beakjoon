#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    string s; cin >> s;
    int ans = 0;
    for(int i=0; i<N; i++){
        if(s[i] == 'A'){
            int cnt = 0;
            i++;
            for(; i<N && s[i] != 'A'; i++){
                if(s[i] == 'N') cnt++;
            }
            if(cnt == 1 && i != N) ans++;
            i--;
        }
    }

    cout << ans << '\n';

    return 0;
}