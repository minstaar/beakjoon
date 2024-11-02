#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<pii> arr(N);
        for(int i=0; i<N; i++) cin >> arr[i].first >> arr[i].second;
        
        int diff = 2e8 + 10;
        for(int i=0; i<N; i++){
            cout << i + 1 << ' ' << arr[i].first + diff << ' ' << arr[i].second + 1 << '\n';
        }
    }

    return 0;
}