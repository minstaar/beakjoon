#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int ans = 0;
    vector<int> arr(N);
    set<int> s;
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=0; i<N; i++){
        if(s.find(arr[i]) != s.end()) continue;
        if(s.size() < 4){
            s.insert(arr[i]);
            ans++;
        }
        else{
            int num, idx  = 0;
            for(auto x: s){
                int tmp = N;
                for(int j=i+1; j<N; j++) if(arr[j] == x) {tmp = j; break;}
                if(idx < tmp){
                    num = x;
                    idx = tmp;
                }
            }
            s.erase(num);
            s.insert(arr[i]);
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}