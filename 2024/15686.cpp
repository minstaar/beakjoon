#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 987654321
using namespace std;

int n, m, ans;
vector<bool> index(20);
vector<pair<int, int>> house, chicken;


void dfs(int closeNum, int curClose, int maxClose)
{
    if(closeNum == maxClose){
        int sum = 0;
        for(int i=0; i<house.size(); i++){
            int dist = MAX;
            for(int j=0; j<chicken.size(); j++){
                if(index[j]) continue;
                dist = min(dist, abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second));
            }
            sum += dist;
        }
        ans = min(ans, sum);
        return;
    }

    if(chicken.size() - curClose <= maxClose - closeNum) return;
    for(int i=curClose+1; i<chicken.size(); i++){
        index[i] = true;
        dfs(closeNum + 1, i, maxClose);
        index[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int t; cin>>t;
            if(t == 1){
                house.push_back({i, j});
            }
            else if(t == 2){
                chicken.push_back({i, j});
            }
        }
    }

    ans = MAX;
    dfs(0, -1, chicken.size() - m);

    cout<<ans;

    return 0;
}
