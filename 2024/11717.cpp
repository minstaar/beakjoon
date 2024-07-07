#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

int H, W;
int arr[25][25], dp[25][25][25][25];

int grundy(int x1, int y1, int x2, int y2)
{
    if(x1 < 1 || x2 < 1 || x2 > H || y2 > W || x1 > x2 || y1 > y2) return 0;
    int &ret = dp[x1][y1][x2][y2];
    if(ret != -1) return ret;
    bitset<25> mex;
    for(int i=x1; i<=x2; i++){
        for(int j=y1; j<=y2; j++){
            if(arr[i][j]) continue;
            int t = grundy(x1, y1, i - 1, j - 1) ^ grundy(x1, j + 1, i - 1, y2) ^ grundy(i + 1, y1, x2, j - 1) ^ grundy(i + 1, j + 1, x2, y2);
            mex[t] = 1;
        }
    }
    ret = 0;
    while(mex[ret]) ret++;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> H >> W;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            char c; cin >> c;
            arr[i][j] = c == 'X';
        }
    }
    memset(dp, -1, sizeof(dp));
    int res = grundy(1, 1, H, W);
    cout << (res ? "First" : "Second") << '\n';
    
    return 0;
}