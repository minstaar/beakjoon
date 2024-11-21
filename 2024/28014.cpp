#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];

    int cnt = 1;
    for(int i=1; i<N; i++){
        if(arr[i-1] <= arr[i]) cnt++;
    }
    cout << cnt << '\n';

    return 0;
}