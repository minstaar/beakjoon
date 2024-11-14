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
    Point operator - (const Point &o) const{
        return {x - o.x, y - o.y};
    }
};

int CCW(Point A, Point B, Point C)
{
    ll op = A.x * B.y + B.x * C.y + C.x * A.y;
    op -= B.x * A.y + C.x * B.y + A.x * C.y;
    return (op > 0) - (op < 0);
}

ll dist(Point A, Point B)
{
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

vector<Point> convexHull(vector<Point>& arr)
{
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
    return hull;
}

ll calipers(vector<Point> & hull)
{
    ll mx = 0;
    for(int i=0, j=0; i<hull.size(); i++){
        while(j + 1 < hull.size() && CCW({0, 0}, hull[i] - hull[i+1], hull[j] - hull[j+1]) >= 0){
            ll cur = dist(hull[i], hull[j]);
            if(cur > mx) mx = cur;
            j++;
        }
        ll cur = dist(hull[i], hull[j]);
        if(cur > mx) mx = cur;
    }
    return mx;
}