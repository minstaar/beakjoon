#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

struct Point
{
    ll x, y;
    bool operator < (const Point &o) const{
        if(y == o.y) return x < o.x;
        return y < o.y;
    }
};

int CCW(Point &A, Point &B, Point&C)
{
    ll op = A.x * B.y + B.x * C.y + C.x * A.y;
    op -= B.x * A.y + C.x * B.y + A.x * C.y;
    return (op > 0) - (op < 0);
}

ll dist(Point &A, Point &B)
{
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

vector<Point> convexHull(vector<Point> &arr)
{
    swap(arr[0], *min_element(arr.begin(), arr.end()));
    sort(arr.begin() + 1, arr.end(), [&](Point &A, Point &B){
        int ccw = CCW(arr[0], A, B);
        if(ccw == 0) return dist(arr[0], A) < dist(arr[0], B);
        return ccw > 0;
    });

    vector<Point> ret;
    for(auto i: arr){
        while(ret.size() > 1 && CCW(ret[ret.size()-2], ret.back(), i) <= 0) ret.pop_back();
        ret.push_back(i);
    }
    return ret;
}

ll area(vector<Point> &arr)
{
    ll ret = 0;
    for(int i=0; i<arr.size(); i++){
        Point A = arr[i], B = arr[(i+1)%arr.size()];
        ret += A.x * B.y - B.x * A.y;
    }
    return abs(ret);
}

bool insidePoly(vector<Point> &arr, Point &P)
{
    int t1 = CCW(arr[0], arr[1], P);
    int t2 = CCW(arr[0], arr.back(), P);
    if(t1 < 0 || t2 > 0) return false;
    if(t1 == 0){
        if(P < arr[0] || arr[1] < P) return false;
        return true;
    }
    if(t2 == 0){
        if(P < arr[0] || arr.back() < P) return false;
        return true;
    }
    int l = 1, r = arr.size() - 1;
    while(l <= r){
        int m = l + r >> 1;
        if(CCW(arr[0], arr[m], P) > 0) l = m + 1;
        else r = m - 1;
    }
    return CCW(arr[r], arr[l], P) >= 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<Point> arr(N), points(M);
    for(int i=0; i<N; i++) cin >> arr[i].x >> arr[i].y;
    for(int i=0; i<M; i++) cin >> points[i].x >> points[i].y;

    auto hull = convexHull(arr);
    if(hull.size() == 1){
        ll cnt = 1;
        for(int i=0; i<M; i++){
            cnt -= (hull[0].x == points[i].x && hull[0].y == points[i].y);
        }
        cout << cnt << '\n';
    }

    else if(hull.size() == 2){
        ll cnt = __gcd(abs(hull[0].x - hull[1].x), abs(hull[0].y - hull[1].y)) + 1;
        for(int i=0; i<M; i++){
            if(CCW(hull[0], hull[1], points[i]) == 0){
                if(points[i] < hull[0] || hull[1] < points[i]) continue;
                else cnt--;
            }
        }
        cout << cnt << '\n';
    }

    else{
        ll s = area(hull);
        ll b = hull.size();
        for(int i=0; i<hull.size(); i++){
            b += __gcd(abs(hull[i].x - hull[(i+1)%hull.size()].x), abs(hull[i].y - hull[(i+1)%hull.size()].y)) - 1;
        }

        ll cnt = (s + b + 2) / 2;
        for(int i=0; i<M; i++){
            cnt -= insidePoly(hull, points[i]);
        }

        cout << cnt << '\n';
    }

    return 0;
}