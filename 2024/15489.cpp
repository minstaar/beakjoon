#include <iostream>
using namespace std;

int arr[55][55];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    arr[1][1] = 1;
    for(int i=1; i<=50; i++){
        arr[i][1] = arr[i][i] = 1;
        for(int j=2; j<i; j++) arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
    }

    int r, c, w; cin >> r >> c >> w;
    int sum = 0;
    for(int i=0; i<w; i++){
        for(int j=0; j<=i; j++) sum += arr[r+i][c+j];
    }

    cout << sum << '\n';

    return 0;
}