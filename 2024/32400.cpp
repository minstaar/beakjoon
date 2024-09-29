#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    double arr[21];
    double a = 0, b = 10.5;
    for(int i=0; i<20; i++) cin >> arr[i];
    if(arr[0] == 20) a = (arr[0] + arr[1] + arr[19]) / 3;
    else if(arr[19] == 20) a = (arr[19] + arr[18] + arr[0]) / 3;
    for(int i=1; i<19; i++){
        if(arr[i] == 20){
            a = (arr[i-1] + arr[i] + arr[i+1]) / 3;
            break;
        }
    }

    if(a > b) cout << "Alice\n";
    else if(a < b) cout << "Bob\n";
    else cout << "Tie\n";

    return 0;
}