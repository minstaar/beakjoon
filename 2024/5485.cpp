#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[5000010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    
    int left = 2 * arr[1] - arr[2];
    int right = arr[1];
    int tmp = left;
    for(int i=3; i<=N; i++){
        if(i % 2){
            tmp = tmp - arr[i-1] + arr[i];
            right = min(right, tmp);
        }
        else{
            tmp = tmp + arr[i-1] - arr[i];
            left = max(left, tmp);
        }
    }
    cout << max(right - left + 1, 0) << '\n';
    
    return 0;
}