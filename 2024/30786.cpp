#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<pii> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    auto getDist = [&](pii a, pii b){
        return abs(a.first - b.first) + abs(a.second - b.second);
    };

    int s = -1, e = -1;
    for(int i=1; i<N; i++){
        if(getDist(arr[i-1], arr[i]) % 2){
            s = i - 1;
            e = i;
            break;
        }
    }

    if(s == -1) cout << "NO\n";
    else{
        cout << "YES\n";
        cout << s + 1 << ' ';
        for(int i=0; i<N; i++){
            if(i == s || i == e) continue;
            cout << i + 1 << ' ';
        }
        cout << e + 1 << '\n';
    }

    return 0;
}