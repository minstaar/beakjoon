#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    string s; cin >> s;
    vector<int> compress;
    int idx = 0, ans = 0, cnt;
    while(idx < N){
        cnt = 1;
        for(; idx<N-1; idx++){
            if(s[idx] != s[idx+1]){
                compress.push_back(cnt);
                break;
            }
            else cnt++;
        }
        idx++;
    }
    compress.push_back(cnt);
    for(int i=0; i<compress.size()-1; i++){
        ans = max(ans, min(compress[i], compress[i+1]));
    }
    cout << ans * 2 << '\n';

    return 0;
}