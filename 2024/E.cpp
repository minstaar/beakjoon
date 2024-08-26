#include <bits/stdc++.h>
using namespace std;

vector<int> res;

int solve(int n)
{
    int cnt = 0;
    while(n % 3 == 0){
        cnt++;
        n /= 3;
    }
    while(n % 5 == 0){
        cnt++;
        n /= 5;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int i=1;
    while(res.size() <= 100000){
        if(solve(i) % 2) continue;
        res.push_back(i);
        i++;
    }

    int T; cin >> T;
    while(T--){
        int a; cin >> a;
        cout << res[a-1] << '\n';
    }

    return 0;
}