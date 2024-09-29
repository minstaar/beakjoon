#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, arr[110];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    int x = N / 2 + 1;
    for(int i=1; i<=N; i+=2){
        arr[i] = x;
        x++;
    }
    x = N / 2;
    for(int i=2; i<=N; i+=2){
        arr[i] = x;
        x--;
    }

    for(int i=1; i<=N; i++) cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}