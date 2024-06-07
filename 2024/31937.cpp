#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data
{
    int time;
    int u;
    int v;
    bool operator < (const Data& other) const{
        return time < other.time;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, K; cin >> N >> M >> K;
    vector<Data> arr(M);
    vector<int> V(K);
    vector<bool> check(N+1);
    for(int i=0; i<K; i++){
        cin >> V[i];
        check[V[i]] = true;
    }
    for(int i=0; i<M; i++){
        cin >> arr[i].time >> arr[i].u >> arr[i].v;
    }
    
    sort(arr.begin(), arr.end());
    int cnt;
    for(int i=0; i<K; i++){
        vector<bool> visited(N+1);
        visited[V[i]] = true;
        cnt = 1;
        bool flag = true;
        for(int j=0; j<M; j++){
            int from = arr[j].u;
            int to = arr[j].v;
            if(visited[from] && !check[to]){
                flag = false;
                break;
            }
            if(check[from] && check[to] && visited[from] && !visited[to]){
                visited[to] = true;
                cnt++;
            }
        }
        
        if(flag && cnt == K){
            cout << V[i] << '\n';
            break;
        }
    }
    
    return 0;
}