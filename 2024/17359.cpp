#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<string> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];

    vector<int> idx(N);
    for(int i=0; i<N; i++) idx[i] = i;
    int ans = 1e9, k = 0;
    for(int i=0; i<N; i++){
        for(int j=1; j<arr[i].size(); j++){
            if(arr[i][j-1] != arr[i][j]) k++;
        }
    }
    do{
        int cnt = 0;
        for(int i=0; i<N; i++){
            if(i != N - 1 && arr[idx[i]].back() != arr[idx[i+1]][0]) cnt++;
        }
        ans = min(ans, k + cnt);
    }while(next_permutation(idx.begin(), idx.end()));

    cout << ans << '\n';

    return 0;
}