#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, K; cin >> N >> M >> K;
    vector<set<int>> lines(N*2);
    vector<int> cnt1(N*2), cnt2(N*2);
    for(int i=0; i<M; i++){
        int y, x; cin >> y >> x;
        lines[y-1].insert(x - 1 + N);
        cnt1[y-1]++;
        cnt2[y-1]++;
        lines[x-1+N].insert(y - 1);
        cnt1[x-1+N]++;
        cnt2[x-1+N]++;
    }

    queue<int> que;
    vector<bool> visited(N*2);
    bool check_h;
    //가로 -> 세로 순서
    int res1 = 1;
    for(int i=0; i<N*2; i++){
        if(lines[i].size() > 0 && lines[i].size() <= K){
            visited[i] = true;
            que.push(i);
        }
    }
    check_h = (que.front() < N);
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        if(cnt1[cur] == 0) continue;
        if((check_h && cur >= N) || (!check_h && cur < N)){
            check_h = !check_h;
            res1++;
        }
        for(auto x: lines[cur]){
            if(cnt1[x] > 0) cnt1[x]--;
            if(!visited[x] && cnt1[x] > 0 && cnt1[x] <= K){
                visited[x] = true;
                que.push(x);
            }
        }
        cnt1[cur] = 0;
    }

    //세로 -> 가로 순서
    visited.clear();
    visited.resize(N*2);
    int res2 = 1;
    for(int i=N*2-1; i>=0; i--){
        if(lines[i].size() > 0 && lines[i].size() <= K){
            visited[i] = true;
            que.push(i);
        }
    }
    check_h = (que.front() < N);
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        if(cnt2[cur] == 0) continue;
        if((check_h && cur >= N) || (!check_h && cur < N)){
            check_h = !check_h;
            res2++;
        }
        for(auto x: lines[cur]){
            if(cnt2[x] > 0) cnt2[x]--;
            if(!visited[x] && cnt2[x] > 0 && cnt2[x] <= K){
                visited[x] = true;
                que.push(x);
            }
        }
        cnt2[cur] = 0;
    }

    int sum1 = 0, sum2 = 0;
    for(int i=0; i<N*2; i++){
        sum1 += cnt1[i];
        sum2 += cnt2[i];
    }
    if(sum1 > 0 && sum2 > 0) cout << -1 << '\n';
    else if(sum1 > 0) cout << res2 << '\n';
    else if(sum2 > 0) cout << res1 << '\n';
    else cout << min(res1, res2) << '\n';

    return 0;
}