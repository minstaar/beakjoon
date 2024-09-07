#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int arr[10], key;
    for(int i=0; i<8; i++) cin >> arr[i];
    cin >> key;
    int sum = 0;
    for(int i=0; i<8; i++){
        cout << (arr[i] & 1) << ' ';
        sum += arr[i];
    }
    cout << endl << (sum & 1) << endl;

    for(int i=0; i<8; i++){
        cout << ((arr[i] ^ key) & 1) << ' ';
    }
    cout << endl << ((sum ^ key) & 1) << endl;

    return 0;
}