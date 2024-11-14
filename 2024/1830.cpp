#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

const ll INF = 1e18;

struct Point
{
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

int N;
vector<Point> arr, convert;

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

vector<Point> convexHull()
{
    swap(arr[0], *min_element(arr.begin(), arr.end()));
    sort(arr.begin() + 1, arr.end(), [](Point &A, Point &B){
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

ll mxUclidean()
{
    auto hull = convexHull();
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

ll mnUclidean()
{
    sort(arr.begin(), arr.end(), [](Point &A, Point &B){
        return A.x < B.x;
    });
    set<Point> s = {arr[0], arr[1]};
    ll mn = dist(arr[0], arr[1]);
    int start = 0;
    for(int i=2; i<N; i++){
        Point cur = arr[i];
        while(start < i){
            if((cur.x - arr[start].x) * (cur.x - arr[start].x) > mn){
                s.erase(arr[start]);
                start++;
            }
            else break;
        }
        ll d = sqrt(mn) + 1;
        auto lower = s.lower_bound(Point(-INF, cur.y - d));
        auto upper = s.upper_bound(Point(INF, cur.y + d));
        for(auto it=lower; it!=upper; it++){
            if(dist(cur, *it) < mn) mn = dist(cur, *it);
        }
    }
    return mn;
}

ll mxManhattan()
{
    ll mxX = -INF, mnX = INF;
    ll mxY = -INF, mnY = INF;
    for(int i=0; i<N; i++){
        mxX = max(mxX, convert[i].x);
        mnX = min(mnX, convert[i].x);
        mxY = max(mxY, convert[i].y);
        mnY = min(mnY, convert[i].y);
    }
    return max(mxX - mnX, mxY - mnY);
}

ll mnManhattan()
{
    sort(arr.begin(), arr.end(), [](Point &A, Point &B){
        return A.x < B.x;
    });
    set<Point> s = {arr[0], arr[1]};
    
    auto mDist = [](Point A, Point B){
        return abs(A.x - B.x) + abs(A.y - B.y);
    };
    
    ll mn = mDist(arr[0], arr[1]);
    int start = 0;
    for(int i=2; i<N; i++){
        Point cur = arr[i];
        while(start < i){
            if(cur.x - arr[start].x > mn){
                s.erase(arr[start]);
                start++;
            }
            else break;
        }
        auto lower = s.lower_bound(Point(-INF, cur.y - mn));
        auto upper = s.upper_bound(Point(INF, cur.y + mn));
        for(auto it=lower; it!=upper; it++){
            if(mDist(cur, *it) < mn) mn = mDist(cur, *it);
        }
        s.insert(cur);
    }
    return mn;
}

ll mxChebyshev()
{
    ll mxX = -INF, mnX = INF;
    ll mxY = -INF, mnY = INF;
    for(int i=0; i<N; i++){
        mxX = max(mxX, arr[i].x);
        mnX = min(mnX, arr[i].x);
        mxY = max(mxY, arr[i].y);
        mnY = min(mnY, arr[i].y);
    }
    return max(mxX - mnX, mxY - mnY);
}

ll mnChebyshev()
{
    sort(convert.begin(), convert.end(), [](Point &A, Point &B){
        return A.x < B.x;
    });
    set<Point> s = {convert[0], convert[1]};
    
    auto mDist = [](Point A, Point B){
        return abs(A.x - B.x) + abs(A.y - B.y);
    };
    
    ll mn = mDist(convert[0], convert[1]);
    int start = 0;
    for(int i=2; i<N; i++){
        Point cur = convert[i];
        while(start < i){
            if(cur.x - convert[start].x > mn){
                s.erase(convert[start]);
                start++;
            }
            else break;
        }
        auto lower = s.lower_bound(Point(-INF, cur.y - mn));
        auto upper = s.upper_bound(Point(INF, cur.y + mn));
        for(auto it=lower; it!=upper; it++){
            if(mDist(cur, *it) < mn) mn = mDist(cur, *it);
        }
        s.insert(cur);
    }
    return mn / 2;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    arr.resize(N);
    for(int i=0; i<N; i++) cin >> arr[i].x >> arr[i].y;

    cout << mxUclidean() << '\n';
    cout << mnUclidean() << '\n';
    
    convert.resize(N);
    for(int i=0; i<N; i++){
        convert[i].x = arr[i].x + arr[i].y;
        convert[i].y = arr[i].x - arr[i].y;
    }

    cout << mxManhattan() << '\n';
    cout << mnManhattan() << '\n';

    cout << mxChebyshev() << '\n';
    cout << mnChebyshev() << '\n';

    return 0;
}