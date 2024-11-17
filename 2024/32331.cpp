#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M;
    ll X, Y;
    cin >> N >> M >> X >> Y;
    vector<ll> arr;
    int g; ll comp; cin >> g >> comp;
    for(int i=0; i<N-1; i++){
        int id; ll score; cin >> id >> score;
        if(id < 2024000000) continue;
        ll tmp = Y - (X - score);
        if(tmp < 0) tmp = 0;
        arr.push_back(score + tmp);
    }

    sort(arr.begin(), arr.end(), greater<>());
    int rank = 1, idx = 0;
    for(int i=1; i<arr.size(); i++){
        if(arr[i-1] > arr[i]){
            if(i + 1 > M) break;
            idx = i;
            rank = i + 1;
        }
    }
    if(arr.size() < M){
        cout << "YES\n";
        cout << 0 << '\n';
    }
    else if(arr[idx] <= comp + Y){
        cout << "YES\n";
        cout << (arr[idx] - comp > 0 ? arr[idx] - comp : 0) << '\n';
    }
    else cout << "NO\n";

    return 0;
}