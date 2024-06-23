#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[110];
int l[110], r[110];
bool visited[110];

struct Data
{
    int a, b, c;
};

int chk(Data x, Data y)
{
    int cnt = 0;
    if(x.a == y.a) cnt++;
    else if(x.a < y.a) return 0;
    if(x.b == y.b) cnt++;
    else if(x.b < y.b) return 0;
    if(x.c == y.c) cnt++;
    else if(x.c < y.c) return 0;
    if(cnt == 3) return 2;
    else return 1;
}

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

    int N; cin >> N;
    vector<Data> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int t = chk(arr[i], arr[j]);
            if(t == 1 || t == 2 && i < j){
                adj[i].push_back(j + N);
            }
        }
    }
    
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    for(int i=0; i<N; i++){
        memset(visited, false, sizeof(visited));
        dfs(i);
        memset(visited, false, sizeof(visited));
        dfs(i);
    }
    int res = 0;
    for(int i=0; i<N; i++){
        res += r[i+N] == -1;
    }
    cout << res << '\n';

    return 0;
}