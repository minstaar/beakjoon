#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Point
{
    ll x, y;
    Point(){};
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

ll dist(Point &A, Point &B)
{
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

vector<Point> arr, hull;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        arr.resize(N);
        for(int i=0; i<N; i++) cin >> arr[i].x >> arr[i].y;

        swap(arr[0], *min_element(arr.begin(), arr.end()));
        sort(arr.begin() + 1, arr.end(), [&](Point &A, Point &B){
            int ccw = CCW(arr[0], A, B);
            if(ccw == 0) return dist(arr[0], A) < dist(arr[0], B);
            return ccw > 0;
        });

        hull.clear();
        for(auto i: arr){
            while(hull.size() > 1 && CCW(hull[hull.size()-2], hull.back(), i) <= 0) hull.pop_back();
            hull.push_back(i);
        }

        ll mx = 0;
        Point ans1, ans2;
        int j = 0;
        for(int i=0; i<hull.size(); i++){
            ll cur;
            while(j + 1 < hull.size() && CCW({0, 0}, hull[i] - hull[i+1], hull[j] - hull[j+1]) >= 0){
                cur = dist(hull[i], hull[j]);
                if(cur > mx){
                    ans1 = hull[i];
                    ans2 = hull[j];
                    mx = cur;
                }
                j++;
            }
            cur = dist(hull[i], hull[j]);
            if(cur > mx){
                ans1 = hull[i];
                ans2 = hull[j];
                mx = cur;
            }
        }
        cout << ans1.x << ' ' << ans1.y << ' ' << ans2.x << ' ' << ans2.y << '\n';
    }

    return 0;
}