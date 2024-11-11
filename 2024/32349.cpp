#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[10010];
int l[10010], r[10010];
bool visited[10010];

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

    int H, W;
    int arr1[110][110], arr2[110][110];
    int cnt1 = 0, cnt2 = 0;

    cin >> W >> H;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> arr1[i][j];
            cnt1 += arr1[i][j];
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> arr2[i][j];
            if(arr1[i][j] & arr2[i][j]){
                arr1[i][j] = arr2[i][j] = false;
                cnt1--;
            }
            cnt2 += arr2[i][j];
        }
    }

    if(cnt1 != cnt2){
        cout << "-1\n";
        return 0;
    }

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(!arr1[i][j]){
                continue;
            }
            for(int k=0; k<4; k++){
                int x = i + "1210"[k] - '1';
                int y = j + "2101"[k] - '1';
                if(x < 0 || x >= H || y < 0 || y >= W || !arr2[x][y]) continue;
                adj[i * W + j].push_back(x * W + y);
            }
        }
    }

    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    int matched = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(!arr1[i][j]) continue;
            if(l[i * W + j] == -1){
                memset(visited, false, sizeof(visited));
                if(dfs(i * W + j)) matched++;
            }
        }
    }
    cout << matched + (cnt1 - matched) * 2 << '\n';

    return 0;
}