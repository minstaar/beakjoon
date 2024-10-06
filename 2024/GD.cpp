#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

ll N, M, arr[1000010];
bool check[1000010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];

    int cnt = 0;
    for(int i=1; i<N; i++){
        if(abs(arr[i] - arr[i-1]) < M && !check[i-1]){
            check[i] = true;
            cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}