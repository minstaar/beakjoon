#include <iostream>
using namespace std;

int arr[1010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int cntA = 0, cntB = 0;
    for(int i=0; i<N; i++){
        int K; cin >> K;
        for(int j=0; j<K; j++){
            cin >> arr[j];
        }
        int idx = 0;
        for(; idx<N; idx++) if(arr[idx] == 1) break;
        cout << (idx >= 475 && idx < 525 ? "Bob" : "Alice") << endl;
    }

    return 0;
}