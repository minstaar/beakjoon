#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int A, B;
    for(int i=1; i<=9; i++){
        cout << "? A " << i << endl;
        int resp; cin >> resp;
        if(resp){
            A = i;
            break;
        }
    }
    for(int i=1; i<=9; i++){
        cout << "? B " << i << endl;
        int resp; cin >> resp;
        if(resp){
            B = i;
            break;
        }
    }
    cout << "! " << A + B << endl;

    return 0;
}