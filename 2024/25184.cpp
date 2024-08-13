#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int x = 1 + N / 2; cout << x << ' ';
    for(int i=1; i<N; i++){
        if(i & 1) x -= N / 2;
        else x += N / 2 + 1;
        cout << x << ' ';
    }
    
    return 0;
}