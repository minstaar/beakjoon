#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];
    
    int cnt = 0;
    while(1){
        bool flag = true;
        for(int i=0; i<N; i++){
            if(arr[i] & 1){
                arr[i]--;
                cnt++;
            }
            arr[i] >>= 1;
            if(arr[i]) flag = false;
        }
        if(flag) break;
        cnt++;
    }
    cout << cnt << '\n';

    return 0;
}