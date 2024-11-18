#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int arr[] = {13, 7, 5, 3, 3, 2};
    double a = 0, b = 0;
    for(int i=0; i<6; i++){
        int x; cin >> x;
        a += arr[i] * x;
    }
    for(int i=0; i<6; i++){
        int x; cin >> x;
        b += arr[i] * x;
    }
    b += 1.5;

    cout << (a > b ? "cocjr0208\n" : "ekwoo\n");

    return 0;
}