#include <iostream>
#include <cmath>
using namespace std;

int ans = 0;
double arr[8], cmp[8];
bool chk[8];

bool isValid(double a1, double a2, double a3)
{
    return sqrt(2) * a2 * (a1 + a3) > 2 * a1 * a3;
}

void solve(int cur)
{
    if(cur == 8){
        if(isValid(cmp[6], cmp[7], cmp[0]) && isValid(cmp[7], cmp[0], cmp[1])) ans++;
        return;
    }

    for(int i=0; i<8; i++){
        if(chk[i]) continue;
        if(cur >= 2 && !isValid(cmp[cur-2], cmp[cur-1], arr[i])) continue;
        chk[i] = true;
        cmp[cur] = arr[i];
        solve(cur + 1);
        chk[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(int i=0; i<8; i++) cin >> arr[i];
    solve(0);

    cout << ans << '\n';

    return 0;
}