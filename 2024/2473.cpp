#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    vector<long long> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr.begin(), arr.end());

    int t1, t2, t3;
    long long ans = 4000000000;
    for(int i=0; i<=n-2; i++){
        int front = i + 1, rear = n - 1;
        while(front < rear){
            long long sum = arr[i] + arr[front] + arr[rear];
            if(abs(ans) > abs(sum)){
                ans = sum;
                t1 = i;
                t2 = front;
                t3 = rear;
            }

            if(sum < 0) front++;
            else if(sum > 0) rear--;
            else{
                cout<<arr[t1]<<" "<<arr[t2]<<" "<<arr[t3];
                return 0;
            }
        }
    }

    cout<<arr[t1]<<" "<<arr[t2]<<" "<<arr[t3];

    return 0;
}
