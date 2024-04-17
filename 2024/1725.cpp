#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N+5);
    stack<int> stck;
    long long ans = 0, tmp, height;

    for(int i=1; i<=N; i++) cin >> arr[i];

    stck.push(0);
    for(int i=1; i<=N+1; i++){
        tmp = 0;
        while(!stck.empty() && arr[stck.top()] > arr[i]){
            height = arr[stck.top()];
            stck.pop();   
            tmp = (i - stck.top() - 1) * height;
            ans = max(ans, tmp);
        }
        stck.push(i);
    }

    cout << ans << '\n';

    return 0;
}