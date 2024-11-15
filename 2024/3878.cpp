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
    Point operator - (const Point &o) const{
        return {x - o.x, y - o.y};
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

bool isIntersect(Point &A, Point &B, Point &C, Point &D)
{
    int line1_2 = CCW(A, B, C) * CCW(A, B, D);
    int line2_1 = CCW(C, D, A) * CCW(C, D, B);
    if(line1_2 == 0 && line2_1 == 0){
        if(B < A) swap(A, B);
        if(D < C) swap(C, D);
        return !(B < C || D < A);
    }
    return line1_2 <= 0 && line2_1 <=0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N, M; cin >> N >> M;
        vector<Point> W(N), B(M);
        for(int i=0; i<N; i++) cin >> W[i].x >> W[i].y;
        for(int i=0; i<M; i++) cin >> B[i].x >> B[i].y;

        if(N <= 2 && M <= 2){
            if(N == 1 && M == 1){
                cout << "YES\n";
            }
            else if(N == 1 && M == 2){
                if(CCW(W[0], B[0], B[1]) == 0){
                    cout << "NO\n";
                }
                else cout << "YES\n";
            }
            else if(N == 2 && M == 1){
                if(CCW(W[0], W[1], B[0]) == 0){
                    cout << "NO\n";
                }
                else cout << "YES\n";
            }
            else{
                if(isIntersect(W[0], W[1], B[0], B[1])) cout << "NO\n";
                else cout << "YES\n";
            }
            continue;
        }

        auto hull1 = convexHull(W), hull2 = convexHull(B);
        bool flag = true;
        for(int i=0; i<hull1.size(); i++){
            for(int j=0; j<hull2.size(); j++){
                if(isIntersect(hull1[i], hull1[(i+1)%hull1.size()], hull2[j], hull2[(j+1)%hull2.size()])){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(!flag){
            cout << "NO\n";
            continue;
        }

        if(hull2.size() >= 3){
            for(int i=0; i<hull1.size(); i++){
                int cnt = 0;
                for(int j=0; j<hull2.size(); j++){
                    int ccw = CCW(hull2[j], hull2[(j+1)%hull2.size()], hull1[i]);
                    cnt += ccw >= 0;
                }
                if(!flag || cnt == hull2.size()){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag){
            cout << "NO\n";
            continue;
        }

        if(hull1.size() >=3){
            for(int i=0; i<hull2.size(); i++){
                int cnt = 0;
                for(int j=0; j<hull1.size(); j++){
                    int ccw = CCW(hull1[j], hull1[(j+1)%hull1.size()], hull2[i]);
                    cnt += ccw >= 0;
                }
                if(!flag || cnt == hull1.size()){
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }

    return 0;
}