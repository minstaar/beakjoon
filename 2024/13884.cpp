#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int K, N; cin >> K >> N;
        vector<int> arr(N);
        multiset<int> s;
        for(int i=0; i<N; i++){
            cin >> arr[i];
            s.insert(arr[i]);
        }
        int cnt = 0;
        for(int i=0; i<N; i++){
            if(arr[i] == *s.begin()){
                s.erase(s.begin());
            }
            else cnt++;
        }
        cout << K << ' ' << cnt << '\n';
    }

    return 0;
}