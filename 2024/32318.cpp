#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int M, ans = 0;
string s;
vector<int> arr[30];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s >> M;
    for(int i=0; i<26; i++){ //for every a~z find identical letters
        int idx = 0;
        for(; idx<s.length(); idx++){
            if(s[idx] == 'a' + i) break;
        }
        if(idx == s.length()) continue;
    
        bool flag = true;
        while(idx < s.length()){
            int cnt = 0;
            for(; idx<s.length(); idx++){
                if(flag){
                    if(s[idx] == 'a' + i) cnt++;
                    else break;
                }
                else{
                    if(s[idx] != 'a' + i) cnt++;
                    else break;
                }
            }
            arr[i].push_back(cnt);
            flag = !flag;
        }

        int l = 0, r = 0, sum = arr[i][0], limit = 0;
        while(l < arr[i].size() && r < arr[i].size()){
            while(limit <= M){
                r += 2;
                if(r >= arr[i].size()) break;
                limit += arr[i][r-1];
                sum += arr[i][r];
                if(limit <= M) ans = max(ans, sum);
            }
            
            while(limit > M && l < r){
                l += 2;
                limit -= arr[i][l-1];
                sum -= arr[i][l-2];
            }

            ans = max(ans, sum);
        }
    }

    cout << ans << '\n';

    return 0;
}