#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int N;
int cnt[1010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    int price;
    for(int i=0; i<N; i++){
        string s; ll t; cin >> s >> t;
        if(s == "jinju") price = t;
        else cnt[min(t, ll(1001))]++;
    }

    int sum = 0;
    for(int i=price+1; i<=1001; i++) sum += cnt[i];
    cout << price << '\n' << sum << '\n';
    return 0;
}