#include <iostream>
#include <vector>
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

int CCW(Point &A, Point &B, Point &C)
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

int insidePoly(vector<Point> &poly, vector<Point> &cmp)
{
    int N = poly.size(), cnt = 0;
    for(auto i: cmp){
        int t1 = CCW(poly[0], poly[1], i);
        int t2 = CCW(poly[0], poly[N-1], i);
        if(t1 <= 0 || t2 >= 0){
            if(t1 == 0){
                if(i < poly[0] || poly[1] < i) continue;
                else cnt++;
            }
            else if(t2 == 0){
                if(i < poly[0] || poly[N-1] < i) continue;
                else cnt++;
            }
            continue;
        }
        int s = 1, e = N - 1;
        while(s <= e){
            int m = s + e >> 1;
            int ccw = CCW(poly[0], poly[m], i);
            if(ccw > 0) s = m + 1;
            else e = m - 1;
        }
        cnt += CCW(poly[e], poly[s], i) >= 0;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<Point> arr1(N), arr2(N);
    for(int i=0; i<N; i++) cin >> arr1[i].x >> arr1[i].y;
    for(int i=0; i<N; i++) cin >> arr2[i].x >> arr2[i].y;

    auto poly1 = convexHull(arr1), poly2 = convexHull(arr2);
    int res1 = insidePoly(poly1, arr2);
    int res2 = insidePoly(poly2, arr1);
    cout << res1 << ' ' << res2 << '\n';

    return 0;
}