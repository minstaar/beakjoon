#include <iostream>
using namespace std;

int prefixSum[1000010];

bool check(int num)
{
    int arr[10], idx = 0;
    bool flag = false;
    while(num > 0){
        arr[idx++] = num % 10;
        num /= 10;
    }
    if(idx <= 2) return false;
    for(int i=idx-1; i>=1; i--){
        if(!flag && arr[i] >= arr[i-1]){
            if(i == idx - 1) return false;
            else flag = true;
        }
        if(flag && arr[i] <= arr[i-1]) return false;
    }
    if(!flag) return false;
    else return true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(int i=120; i<=1e6; i++){
        if(check(i)) prefixSum[i] = prefixSum[i-1] + 1;
        else prefixSum[i] = prefixSum[i-1];
    }

    int Q; cin >> Q;
    while(Q--){
        int s, e; cin >> s >> e;
        cout << prefixSum[e] - prefixSum[s-1] << '\n';
    }

    return 0;
}