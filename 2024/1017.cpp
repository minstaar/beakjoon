#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[55];
int l[55], r[55];
bool isPrime[2010], visit[55];

void prime()
{
    for(int i=1; i<=2000; i++){
        bool flag = true;
        for(int j=2; j*j<=i; j++){
            if(i % j == 0){
                flag = false;
                break;
            }
        }
        if(flag) isPrime[i] = true;
    }
}

bool dfs(int a)
{
    if(visit[a]) return false;
    visit[a] = true;
    for(auto b: adj[a]){
        if(r[b] == -1 || !visit[r[b]] && dfs(r[b])){
            l[a] = b;
            r[b] = a;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int firstNum;
    vector<int> a, b;
    for(int i=0; i<N; i++){
        int x; cin >> x;
        if(i == 0) firstNum = x;
        if(x % 2) a.push_back(x);
        else b.push_back(x);
    }

    if(firstNum % 2 == 0) swap(a, b);
    prime();
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            if(isPrime[a[i]+b[j]]) adj[i].push_back(j);
        }
    }

    vector<int> res;
    for(auto i: adj[0]){
        memset(l, -1, sizeof(l));
        memset(r, -1, sizeof(r));
        l[0] = i, r[i] = 0;
        int match = 1;
        for(int j=1; j<a.size(); j++){
            if(l[j] == -1){
                memset(visit, false, sizeof(visit));
                visit[0] = true;
                if(dfs(j)) match++;
            }
        }
        if(match == a.size()) res.push_back(b[i]);
    }

    if(a.size() != b.size() || res.empty()){
        cout << -1 << '\n';
    }
    else{
        sort(res.begin(), res.end());
        for(auto x: res) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}