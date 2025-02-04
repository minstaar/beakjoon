#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Point
{
    ll x, y;
    int idx;
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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<Point> arr(N);
        for(int i=0; i<N; i++) {
            cin >> arr[i].x >> arr[i].y;
            arr[i].idx = i;
        }

        swap(arr[0], *min_element(arr.begin(), arr.end()));
        sort(arr.begin() + 1, arr.end(), [&](Point &A, Point &B){
            int ccw = CCW(arr[0], A, B);
            if(ccw == 0) return dist(arr[0], A) < dist(arr[0], B);
            return ccw > 0;
        });

        int pv = N-1;
        while(CCW(arr[pv], arr[pv-1], arr[0]) == 0) pv--;
        reverse(arr.begin() + pv, arr.end());
        for(int i=0; i<N; i++) cout << arr[i].idx << ' ';
        cout << '\n';
    }

    return 0;
}