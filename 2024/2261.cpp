#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
    Point(){}
    Point(int x, int y): x(x), y(y) {}
};

struct cmpY
{
    bool operator () (const Point &a, const Point &b) const{
        if(a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<Point> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i].x >> arr[i].y;
    sort(arr.begin(), arr.end(), [](Point &a, Point &b){
        return a.x < b.x;
    });

    auto getDist = [](Point a, Point b){
        return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
    };

    set<Point, cmpY> s = {arr[0], arr[1]};
    int mn = getDist(arr[0], arr[1]), start = 0;
    for(int i=2; i<N; i++){
        Point cur = arr[i];
        while(start < i){
            if((cur.x - arr[start].x) * (cur.x - arr[start].x) > mn){
                s.erase(arr[start]);
                start++;
            }
            else break;
        }

        int d = sqrt(mn) + 1;
        auto lower = s.lower_bound(Point(-10000, cur.y - d));
        auto upper = s.upper_bound(Point(10000, cur.y + d));
        for(auto it=lower; it!=upper; it++){
            int t = getDist(*it, cur);
            if(t < mn) mn = t;
        }

        s.insert(cur);
    }

    cout << mn << '\n';

    return 0;
}