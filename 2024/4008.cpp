#include <iostream>
#include <vector>
using namespace std;

struct Line
{
    long long p, q;
    double cross;
};

int n;
int a, b, c;
long long x[1000010], psum[1000010], dp[1000010];
vector<Line> vec;

double checkCross(Line& f, Line& g)
{
    return (double)(g.q - f.q) / (f.p - g.p);
}

long long adjust(long long x)
{
    return a * x * x + b * x + c;
}

long long slope(int i)
{
    return -2 * a * psum[i];
}

long long inter(int i)
{
    return a * psum[i] * psum[i] - b * psum[i] + dp[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> a >> b >> c;
    vector<Line> vec;

    for(int i=1; i<=n; i++){
        cin >> x[i];
        psum[i] = psum[i-1] + x[i];
    }

    long long xpos = 0;
    dp[1] = adjust(psum[1]);
    vec.push_back({slope(1), inter(1), 0.0});

    for(int i=2; i<=n; i++){
        long long x = psum[i];
        while (xpos + 1 < vec.size() && vec[xpos+1].cross < x) xpos++;
        dp[i] = max(adjust(psum[i]), vec[xpos].p * x + vec[xpos].q + adjust(psum[i]));

        Line next = {slope(i), inter(i), 0.0};
        while(vec.size() >= 1){
            double cross = checkCross(vec.back(), next);
            if(cross <= vec.back().cross) vec.pop_back();
            else break;
        }
        next.cross = checkCross(vec.back(), next);
        vec.push_back(next);
        if(xpos >= vec.size()) xpos = vec.size() - 1;
    }

    cout << dp[n] << '\n';

    return 0;
}