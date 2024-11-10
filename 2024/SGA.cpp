#include <iostream>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    pii A, B, X;
    cin >> A.first >> A.second >> B.first >> B.second >> X.first >> X.second;
    if(A.first != B.first && A.second != B.second){
        cout << "1\n";
    }
    else{
        if(A.first == B.first && A.first == X.first && (A.second <= X.second && X.second <= B.second || A.second >= X.second && X.second >= B.second) || A.second == B.second && A.second == X.second && (A.first <= X.first && X.first <= B.first || A.first >= X.first && X.first >= B.first)){
            cout << "2\n";
        }
        else cout << "0\n";
    }

    return 0;
}