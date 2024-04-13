#include <iostream>
#include <vector>
using namespace std;

int n, k, ptr;
long long arr[100010], psum[100010], dp[210][100010];
const long long INF = 1e10;

struct Line
{
    long long m, b;
    double x;
    Line(long long _m, long long _b, double _x) : m(_m), b(_b), x(_x) {};
    long long f(long long x)
    {
        return m * x + b;
    }
};
vector<Line> lines;

double intersection(Line& f, Line& g)
{
    return (double)(g.b - f.b) / (f.m - g.m);
}

void addLine(long long m, long long b)
{
    Line cur(m, b, -INF);
    if(lines.empty()){
        lines.push_back(cur);
        return;
    }
    while(!lines.empty()){
        double x = intersection(lines.back(), cur);
        if(x < lines.back().x || (x == lines.back().x && cur.b > lines.back().b)) lines.pop_back();
        else break;
    }
    cur.x = intersection(lines.back(), cur);
    lines.push_back(cur);
    if(ptr >= lines.size()) ptr = lines.size() - 1;
}

long long slope(int j)
{
    return psum[j];
}

long long inter(int i, int j)
{
    return dp[i][j] - psum[j] * psum[j];
}

long long query(long long x)
{
    while(ptr + 1 < lines.size() && lines[ptr+1].x < x) ptr++;
    return lines[ptr].f(x);
}

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
        lines.clear();
        addLine(0, 0);
        for(int j=1; j<=n; j++){
            dp[i][j] = query(psum[j]);
            if(query(psum[j])<0) cout<<i<<" "<<j<<endl;
            addLine(slope(j), inter(i-1, j));
        }
    }

    cout << dp[k][n] << '\n';

    return 0;
}