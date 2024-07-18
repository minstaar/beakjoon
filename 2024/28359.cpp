#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    int duplicate = 0, tmp = arr[0], sum = arr[0];
    for(int i=1; i<N; i++){
        if(arr[i-1] != arr[i]){
            duplicate = max(duplicate, tmp);
            tmp = arr[i];
        }
        else tmp += arr[i];
        sum += arr[i];
    }
    duplicate = max(duplicate, tmp);

    cout << sum + duplicate << '\n';
    for(int i=0; i<N; i++) cout << arr[i] << ' ';

    return 0;
}