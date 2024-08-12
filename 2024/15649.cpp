#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;

void solve(int k)
{
    if(k == M){
        for(auto x: arr) cout << x << ' ';
        cout << '\n';
        return;
    }
    for(int i=1; i<=N; i++) if(find(arr.begin(), arr.end(), i) == arr.end()){
        arr.push_back(i);
        solve(k + 1);
        arr.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    solve(0);

    return 0;
}