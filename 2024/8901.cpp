#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data
{
    int val;
    int n1, n2;
    bool operator < (const Data &o) const{
        return val > o.val;
    }
};

vector<Data> arr(3);
int cnt[3], sum;

int solve()
{
    int ret = 0, used[3] = {};
    for(int i=0; i<3; i++){
        auto [val, n1, n2] = arr[i];
        if(cnt[n1] == 0 || cnt[n2] == 0) continue;
        int t = min(cnt[n1], cnt[n2]);
        ret += val * t;
        cnt[n1] -= t, cnt[n2] -= t;
        used[i] = t;
    }

    for(int i=0; i<3; i++){
        if(cnt[i] > 1){
            for(int j=0; j<3; j++){
                auto [val, n1, n2] = arr[j];
                if(n1 != i && n2 != i){
                    if(sum - val > val){
                        int t = min(cnt[i] / 2, used[j]);
                        ret -= val * t;
                        ret += (sum - val) * t;
                    }
                }
            }
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int A, B, C; cin >> A >> B >> C;
        int ab, bc, ca; cin >> ab >> bc >> ca;
        arr[0] = {ab, 0, 1};
        arr[1] = {bc, 1, 2};
        arr[2] = {ca, 0, 2};
        cnt[0] = A, cnt[1] = B, cnt[2] = C;
        sum = ab + bc + ca;
        sort(arr.begin(), arr.end());
        cout << solve() << '\n';
    }

    return 0;
}