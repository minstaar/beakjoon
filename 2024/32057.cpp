#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<pair<int, string>> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end());
    vector<char> res;
    for(int i=0; i<=N; i++){
        vector<char> str(M+1);
        bool flag = true;
        int len = 0;
        for(int j=0; j<N; j++){
            if(j == i) continue;
            auto [idx, s] = arr[j];
            for(int k=0; k<s.length(); k++){
                if(str[k+idx-1] == 0){
                    str[k+idx-1] = s[k];
                    len++;
                }
                else if(str[k+idx-1] != s[k]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag && len == M){
            if(res.size() == 0) res = str;
            else{
                for(int i=0; i<M; i++){
                    if(res[i] != str[i]){
                        cout << -2;
                        return 0;
                    }
                }
            }
        }
    }
    if(res.size() == 0){
        cout << -1;
        return 0;
    }
    else{
        for(int i=0; i<M; i++) cout << res[i];
    }

    return 0;
}