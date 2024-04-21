#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e10;
int N, ptr;
pair<int, int> arr[50010], sorted[50010];
long long dp[50010];

struct  Line
{
    long long m, b;
    double cross;
    Line(long long _m, long long _b, double _cross) : m(_m), b(_b), cross(_cross) {};
    long long f(long long x)
    {
        return m * x + b;
    }
};
vector<Line> lines;

double intersect(Line& a, Line& b)
{
    return (b.b - a.b) / (a.m - b.m);
}

void addLine(long long m, long long b)
{
    Line cur(m, b, -INF);
    if(lines.empty()){
        lines.push_back(cur);
        return;
    }
    while(!lines.empty()){
        double cross = intersect(lines.back(), cur);
        if(cross <= lines.back().cross) lines.pop_back();
        else break;
    }
    cur.cross = intersect(lines.back(), cur);
    lines.push_back(cur);
    if(ptr >= lines.size()) ptr = lines.size() - 1;
    return;
}

long long query(long long x)
{
    while(ptr + 1 < lines.size() && lines[ptr+1].cross < x) ptr++;
    return lines[ptr].f(x);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+N);
    int idx = 0;
    for(int i=0; i<N; i++){
        while(idx > 0 && sorted[idx-1].second <= arr[i].second) idx--;
        sorted[idx++] = arr[i];
    }

    N = idx;
    addLine(sorted[0].second, 0);
    for(int i=0; i<N-1; i++){
        dp[i] = query(sorted[i].first);
        addLine(sorted[i+1].second, dp[i]);
    }
    cout << query(sorted[N-1].first) << '\n';

    return 0;
}