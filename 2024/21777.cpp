#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int N, arr[1000010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    map<int, int> start, end;
    map<int, pair<int, int>> res;
    int prev = 0, t = 1;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        if(prev >= arr[i]) t++;
        if(start.find(arr[i]) == start.end()) start[arr[i]] = t;
        else start[arr[i]] = min(start[arr[i]], t);
        if(end.find(arr[i]) == end.end()) end[arr[i]] = t;
        else end[arr[i]] = max(end[arr[i]], t);
        prev = arr[i];
    }
    for(int i=0; i<N; i++){
        res[arr[i]] = {end[arr[i]] - start[arr[i]] + 1, N - start[arr[i]] - 1};
    }

    cout << res.size() << '\n';
    for(auto x: res){
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << '\n';
    }

    return 0;
}