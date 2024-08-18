#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[4] = {0, 1, 3, 2};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    if(N == 2) cout << "NO\n";
    else{
        cout << "YES\n";
        for(int i=1; i<=N; i++){
            if(i < 4) cout << arr[i] << ' ';
            else cout << i << ' ';
        }
    }

    return 0;
}