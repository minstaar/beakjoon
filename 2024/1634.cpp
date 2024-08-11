#include <iostream>
#include <algorithm>
using namespace std;

int K, N, arr[2500], cmp[2500];

int solve(int s1, int e1, int s2, int e2)
{
    if(s1 == e1) return arr[s1] == cmp[s2];
    int m1 = s1 + e1 >> 1;
    int m2 = s2 + e2 >> 1;
    int ret1 = solve(s1, m1, s2, m2) + solve(m1 + 1, e1, m2 + 1, e2);
    int ret2 = solve(s1, m1, m2 + 1, e2) + solve(m1 + 1, e1, s2, m2);
    return max(ret1, ret2);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> K;
    N = 1 << (K - 1);
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=0; i<N; i++) cin >> cmp[i];

    cout << solve(0, N - 1, 0, N - 1) << '\n';

    return 0;
}