#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, ptr, top;
long long arr[100010], psum[100010], dp[2][100010];
int track[210][100010];
const long long INF = 1e10;

struct Line
{
    long long m[100010], b[100010];
    //double x;
    int idx[100010];
    //Line(long long _m, long long _b, double _x, int _idx) : m(_m), b(_b), x(_x), idx(_idx) {};

    void addLine(long long mm, long long bb, int pp)
    {
        if(top == 0){
            m[top] = mm;
            b[top] = bb;
            idx[top++]=pp;
            return;
        }
        if(top >= 1 && mm == m[top-1]){
            idx[top-1] = pp;
            return;
        }
        while(top > 0){
            if((bb - b[top-1]) * (m[top-2] - m[top -1])  <= (b[top-1] - b[top-2]) * (m[top-1] - mm)) top--;
            else break;
        }
        m[top] = mm;
        b[top] = bb;
        idx[top++]=pp;
        if(ptr >= top) ptr = top - 1;
    }

    pair<long long, int> query(long long x)
    {
        while(ptr + 1 < top && m[ptr] * x + b[ptr] < m[ptr+1] * x + b[ptr+1]) ptr++;
        return {m[ptr] * x + b[ptr], idx[ptr]};
    }
}lines;
vector<int> ans;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
    }

    for(int i=1; i<=k; i++){
        ptr = 0;
        top = 0;
        lines.addLine(0, 0, 0);
        for(int j=1; j<=n; j++){
            pair<long long, int> val = lines.query(psum[j]);
            dp[i&1][j] = val.first;
            track[i][j] = val.second;
            lines.addLine(psum[j], dp[(i-1)&1][j] - psum[j] * psum[j], j);
        }
    }

    cout << dp[k&1][n] << '\n';

    int cur = n;
    ans.push_back(-1);
    for(int i=k; i>=1; i--){
        ans.push_back(track[i][cur]);
        cur = track[i][cur];
    }
    sort(ans.begin(), ans.end());
    for(int i=1; i<=k; i++){
        if(ans[i] == 0) ans[i] = 1;
        if(ans[i] <= ans[i-1]) ans[i] = ans[i-1] + 1;
    }
    for(int i=1; i<=k; i++) cout << ans[i]<<" ";

    return 0;
}