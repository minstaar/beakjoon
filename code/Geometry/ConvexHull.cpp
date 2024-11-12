//BOJ #1708.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point{
    ll x, y;
    Point() {};
    Point(ll x, ll y): x(x), y(y) {};
    bool operator < (const Point &o) const{
        if(y == o.y) return x < o.x;
        return y < o.y;
    }
};

int CCW(Point A, Point B, Point C)
{
    ll op = A.x * B.y + B.x * C.y + C.x * A.y;
    op -= B.x * A.y + C.x * B.y + A.x * C.y;
    if(op > 0) return 1;
    else if(op == 0) return 0;
    else return -1;
}

ll dist(Point A, Point B)
{
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<Point> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i].x >> arr[i].y;

    swap(arr[0], *min_element(arr.begin(), arr.end()));
    sort(arr.begin() + 1, arr.end(), [&](Point &A, Point &B){
        int ccw = CCW(arr[0], A, B);
        if(ccw == 0) return dist(arr[0], A) < dist(arr[0], B);
        return ccw > 0;
    });

    vector<Point> hull;
    for(auto i: arr){
        while(hull.size() > 1 && CCW(hull[hull.size()-2], hull.back(), i) <= 0) hull.pop_back();
        hull.push_back(i);
    }

    cout << hull.size() << '\n';

    return 0;
}