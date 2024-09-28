#include <iostream>
#include <algorithm>
using namespace std;

int arr[100010], cycle[65540];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    
    sort(arr, arr + N);
    int ans = 0;
    for(int i=0; i<N; i++){
        int mn = 1e9, idx = 0;
        for(int j=1; j<=arr[i]; j++){
            if(cycle[j] == 0){
                idx = j;
                break;
            }
            if(mn > cycle[j]){
                mn = cycle[j];
                idx = j;
            }
        }
        for(int j=idx; j<=arr[N-1]; j+=arr[i]){
            cycle[j]++;
            ans = max(ans, cycle[j]);
        }
    }

    cout << ans << '\n';
    return 0;
}