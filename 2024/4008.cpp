#include <iostream>
#include <vector>
using namespace std;

struct Line
{
    long long p, q;
    double cross;
};

double checkCross(Line& f, Line& g)
{
    return (double)(g.q - f.q) / (f.p - g.p);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    vector<int> x(n+1);
    vector<long long> psum(n+1), dp(n+1);
    vector<Line> vec;

    for(int i=0; i<n; i++){
        cin >> x[i];
        psum[i] = i > 0 ? psum[i-1] + x[i] : x[i];
    }

    long long xpos = 0;
    vec.push_back({b, 0, 0.0});
    for(int i=0; i<n; i++){
        Line next = {(-2 * a + psum[i] + b), (dp[i] + a * psum[i] * psum[i] - b * psum[i]), 0.0};

        while(vec.size() >= 1){
            next.cross = checkCross(next, vec.back());
            if(next.cross < vec.back().cross) vec.pop_back();
            else break;
        }
        vec.push_back(next);

        while(xpos + 1 < vec.size() && vec[xpos+1].cross < psum[i]) xpos++;
        dp[i] = vec[xpos].p * psum[i] + vec[xpos].q + a * psum[i] * psum[i] + c;
        cout<<xpos<<" "<<dp[i]<<endl;
    }

    cout << dp[n-1] << '\n';

    return 0;
}