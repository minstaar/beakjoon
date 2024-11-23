#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;

struct Point
{
    ll x, y;
}arr[10010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i].x >> arr[i].y;

    double area = 0;
    for(int i=0; i<N; i++){
        Point A = arr[i], B = arr[(i+1)%N];
        area += A.x * B.y - B.x * A.y;
    }
    area = abs(area) / 2;
    cout << fixed << setprecision(1) << area << '\n';

    return 0;
}