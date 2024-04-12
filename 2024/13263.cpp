#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Line
{
    long long a, b;
    double cross;
};

double checkCross(Line& f, Line& g)
{
    return (g.b - f.b) / (f.a - g.a);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    vector<int> a(n), b(n);
    vector<Line> vec;
    vector<long long> dp(n); //dp[i] = min(a[i]b[j] + dp[j]);

    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    for(int i=1; i<n; i++){
        Line next = {b[i-1], dp[i-1], 0.0};

        while(vec.size() >= 1){
            next.cross = checkCross(next, vec.back());
            if(next.cross < vec.back().cross) vec.pop_back();
            else break;
        }

        vec.push_back(next);

        long long x = a[i];
        int p = 0;
        int left = 0, right = vec.size() - 1;
        while(left <= right){
            int middle = (left + right) / 2;
            if(vec[middle].cross < x){
                p = middle;
                left = middle + 1;
            }
            else right = middle - 1;
        }
        dp[i] = vec[p].a * x + vec[p].b;
    }

    cout<<dp[n - 1];

    return 0;
}