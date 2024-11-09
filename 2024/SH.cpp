#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int arr[100010];
    for(int i=0; i<N; i++) cin >> arr[i];

    for(int i=N-1; i>=1; i--){
        if(N % i) continue;
        bool flag = true;
        int cmp = *min_element(arr, arr + i) + *max_element(arr, arr + i);
        for(int j=i; j<N; j+=i){
            int tmp = *min_element(arr + j, arr + j + i) + *max_element(arr + j, arr + j + i);
            if(cmp != tmp){flag = false; break;}
        }
        if(flag){
            cout << 1;
            return 0;
        }
    }
    cout << 0;

    return 0;
}