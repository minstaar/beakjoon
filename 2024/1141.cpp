#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<string> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end(),[](string a, string b) -> bool{
        if(a.length() == b.length()) return a < b;
        return a.length() > b.length();
    });

    int cnt = 0;
    set<string> s;
    for(int i=0; i<N; i++){
        if(s.empty()){
            for(int j=0; j<arr[i].length(); j++){
                s.insert(arr[i].substr(0, j + 1));
            }
            cnt++;
        }
        else{
            if(s.find(arr[i]) == s.end()){
                cnt++;
                for(int j=0; j<arr[i].length(); j++){
                    s.insert(arr[i].substr(0, j + 1));
                }
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}