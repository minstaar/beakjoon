#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    map<string, int> mp;
    for(int i=0; i<N; i++){
        int num, k; cin >> num >> k;
        for(int j=0; j<k; j++){
            string s; cin >> s;
            mp[s]++;
        }
    }
    bool flag;
    int cnt = 0;
    string res;
    for(auto it=mp.begin(); it!=mp.end(); it++){
        if(cnt < it->second){
            flag = true;
            res = it->first;
            cnt = it->second;
        }
        else if(cnt == it->second){
            flag = false;
        }
    }
    if(!flag) cout << "-1\n";
    else cout << res << '\n';

    return 0;
}