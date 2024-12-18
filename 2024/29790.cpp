#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, U, L; cin >> N >> U >> L;
    if(N >= 1000){
        if(U >= 8000 || L >= 260) cout << "Very Good\n";
        else cout << "Good\n";
    }
    else cout << "Bad\n";

    return 0;
}