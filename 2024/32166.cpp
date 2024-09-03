#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

double dist(double x1, double y1, double x2, double y2)
{
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    double x1, y1, v1; cin >> x1 >> y1 >> v1;
    double x2, y2, v2; cin >> x2 >> y2 >> v2;
    double x3, y3, v3; cin >> x3 >> y3 >> v3;
    int w1, w2, w3; cin >> w1 >> w2 >> w3;
    
    double d1 = dist(x1, y1, x2, y2);
    double d2 = dist(x2, y2, x3, y3);
    double d3 = dist(x3, y3, x1, y1);
    double dsum = d1 + d2 + d3;

    double ans1 = 0, ans2 = 0, ans3 = 0;

    //초기 위치가 p2, p3인 경우
    if(v1 == 0){
        if(v2 <= v3){ //만날 가능성 x
            double t = (d3 + d1) / (v3 - v2);
            if((t * v3) - (d3 + d1) > EPS && (t * v3) - dsum < EPS && w2 == 1){
                ans2 = dsum / v2;
                ans3 = t + (dsum - t * v3) / v2;
            }
            else{
                ans2 = dsum / v2;
                ans3 = dsum / v3;
            }
        }
        else{ //w3, w1에서 만날 가능성 확인
            ans3 = dsum / v3;
            double t = d2 / (v2 - v3); //만날 때까지 걸린 시간
            if(t * v3 > EPS && t * v3 - d3 < EPS && w3 == 1){ //w3도로에서 만날 경우
                ans2 = t + (d3 - t * v3) / v3 + d1 / v2;
            }
            else if(t * v3 - d3 > EPS && t * v3 - (d3 + d1) < EPS && w1 == 1){ //w1도로에서 만날 경우
                ans2 = t + (d3 + d1 - t * v3) / v3;
            }
            else ans2 = dsum / v2;
        }
    }
    
    //초기 위치가 p3, p1인 경우
    if(v2 == 0){
        if(v3 <= v1){ //만날 가능성 x
            double t = (d1 + d2) / (v1 - v3);
            if(t * v1 - (d1 + d2) > EPS && t * v1 - dsum < EPS && w3 == 1){
                ans3 = dsum / v3;
                ans1 = t + (dsum - t * v1) / v3;
            }
            else{
                ans1 = dsum / v1;
                ans3 = dsum / v3;
            }
        }
        else{ //w1, w2에서 만날 가능성 확인
            ans1 = dsum / v1;
            double t = d3 / (v3 - v1); //만날 때까지 걸린 시간
            if(t * v1 > EPS && t * v1 - d1 < EPS && w1 == 1){ //w1도로에서 만날 경우
                ans3 = t + (d1 - t * v1) / v1 + d2 / v3;
            }
            else if(t * v1 - d1 > EPS && t * v1 - (d1 + d2) < EPS && w2 == 1){ //w2도로에서 만날 경우
                ans3 = t + (d1 + d2 - t * v1) / v1;
            }
            else ans3 = dsum / v3;
        }
    }

    //초기 위치가 p1, p2인 경우
    if(v3 == 0){
        if(v1 <= v2){ //만날 가능성 x
            double t = (d2 + d3) / (v2 - v1);
            if(t * v2 - (d2 + d3) > EPS && t * v2 - dsum < EPS && w1 == 1){
                ans1 = dsum / v1;
                ans2 = t + (dsum - t * v2) / v1;
            }
            else{
                ans1 = dsum / v1;
                ans2 = dsum / v2;
            }
        }
        else{ //w2, w3에서 만날 가능성 확인
            ans2 = dsum / v2;
            double t = d1 / (v1 - v2); //만날 때까지 걸린 시간
            if(t * v2 > EPS && t * v2 - d2 < EPS && w2 == 1){ //w2도로에서 만날 경우
                ans1 = t + (d2 - t * v2) / v2 + d3 / v1;
            }
            else if(t * v2 - d2 > EPS && t * v2 - (d2 + d3) < EPS && w3 == 1){ //w3도로에서 만날 경우
                ans1 = t + (d2 + d3 - t * v2) / v2;
            }
            else ans1 = dsum / v1;
        }
    }

    cout << fixed << setprecision(6);

    if(ans1 == 0.0) cout << '-' << '\n';
    else cout << ans1 << '\n';
    if(ans2 == 0.0) cout << '-' << '\n';
    else cout << ans2 << '\n';
    if(ans3 == 0.0) cout << '-' << '\n';
    else cout << ans3 << '\n';

    return 0;
}