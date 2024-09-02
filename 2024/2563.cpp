#include <iostream>
using namespace std;

int arr[110][110];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    int res = 0;
    while(T--){
        int x, y; cin >> x >> y;
        for(int i=x; i<x+10; i++){
            for(int j=y; j<y+10; j++){
                if(arr[i][j] == 0) res += 1;
                arr[i][j] = 1;
            }
        }
    }
    cout << res << '\n';

    return 0;
}