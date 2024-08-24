#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    char resp;
    do{cout << "? 1" << endl;} while(cin >> resp && resp == 'N');
    cout << "! 1" << endl;

    return 0;
}