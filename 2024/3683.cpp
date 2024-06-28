#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

int l[510], r[510];
bool visited[510];
vector<int> adj[510];

bool dfs(int a)
{
    if(visited[a]) return false;
    visited[a] = true;
    for(auto b: adj[a]){
        if(r[b] == -1 || !visited[r[b]] && dfs(r[b])){
            l[a] = b, r[b] = a;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int c, d, v; cin >> c >> d >> v;
        vector<pii> a, b;
        for(int i=0; i<v; i++){
            string str1, str2; cin >> str1 >> str2;
            if(str1[0] == 'C'){
                a.push_back({stoi(str1.substr(1)), stoi(str2.substr(1))});
            }
            else b.push_back({stoi(str1.substr(1)), stoi(str2.substr(1))});
        }
        for(int i=0; i<a.size(); i++) adj[i].clear();
        
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<b.size(); j++){
                if(a[i].first == b[j].second || a[i].second == b[j].first){
                    adj[i].push_back(j);
                }
            }
        }
        memset(l, -1, sizeof(l));
        memset(r, -1, sizeof(r));
        int match = 0;
        for(int i=0; i<a.size(); i++){
            if(l[i] == -1){
                memset(visited, false, sizeof(visited));
                if(dfs(i)) match++;
            }
        }
        cout << v - match << '\n';
    }

    return 0;
}