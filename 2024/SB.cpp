#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int p, q, r, s; cin >> p >> q >> r >> s;
    int a; cin >> a;
    int arr[100] = {0, a};
    for(int i=1; i<=N; i++){
        arr[i*2] = p * arr[i] + q;
        arr[i*2+1] = r * arr[i] + s;
    }
    int sum = 0;
    for(int i=1; i<=N; i++) sum += arr[i];
    cout << sum << '\n';

    return 0;
}