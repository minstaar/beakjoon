#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    int arr[1010], s = 0, ans = 0;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        s ^= arr[i];
    }

    for(int i=0; i<N; i++){
        if((arr[i] ^ s) < arr[i]) ans++;
    }
    cout << ans << '\n';

    return 0;
}