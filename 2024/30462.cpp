#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[200010], cnt[200010];
bool used[200010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    priority_queue<int, vector<int>, greater<>> pq;
    bool flag = true;
    vector<int> res;
    
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        if(arr[i-1] > arr[i]){
            flag = false;
        }
        cnt[arr[i]]++;
    }

    for(int i=1; i<=N; i++){
        if(cnt[i] == 0) pq.push(i);
    }
    for(int i=1; i<=N; i++){
        if(arr[i] > i + 1 || pq.empty() || used[pq.top()]){
            flag = false;
            break;
        }
        used[pq.top()] = true;
        res.push_back(pq.top());
        pq.pop();
        if(--cnt[arr[i]] == 0) pq.push(arr[i]);
    }
    
    if(flag && res.size() == N){
        cout << "Yes" << '\n';
        for(auto x: res) cout << x << ' ';
    }
    else cout << "No" << '\n';

    return 0;
}