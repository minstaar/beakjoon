#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<string> str(N);
    vector<int> adj[30], inDegree(30);
    vector<bool> check(30);
    int cnt = 0;
    bool isPossible = true;
    for(int i=0; i<N; i++) cin >> str[i];
    for(int i=0; i<N; i++){
        for(auto j: str[i]){
            if(!check[j-'a']){
                check[j-'a'] = true;
                cnt++;
            }
        }
    }

    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            for(int k=0; k<min(str[i].length(), str[j].length()); k++){
                if(str[i][k] != str[j][k]){
                    adj[str[i][k]-'a'].push_back(str[j][k]-'a');
                    inDegree[str[j][k]-'a']++;
                    break;
                }
                if(k == min(str[i].length(), str[j].length()) - 1 && str[i].length() > str[j].length()){
                    isPossible = false;
                }
            }
        }
    }

    queue<int> que;
    vector<char> ans;
    bool isOnly = true;
    for(int i=0; i<26; i++){
        if(check[i] && inDegree[i] == 0) que.push(i);
    }
    for(int i=0; i<cnt; i++){
        if(que.empty()){
            isPossible = false;
            break;
        }
        else if(que.size() > 1){
            isOnly = false;
        }
        int cur = que.front();
        que.pop();
        ans.push_back('a' + cur);
        for(auto next: adj[cur]){
            inDegree[next]--;
            if(inDegree[next] == 0){
                que.push(next);
            }
        }
    }

    if(!isPossible){
        cout << '!' << '\n';
    }
    else{
        if(!isOnly){
            cout << '?' << '\n';
        }
        else{
            for(auto x: ans) cout << x;
            cout << '\n';
        }
    }

    return 0;
}