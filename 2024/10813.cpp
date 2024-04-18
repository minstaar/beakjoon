#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<int> arr(N+1);
    for(int i=1; i<=N; i++){
        arr[i] = i;
    }
    for(int i=1; i<=M; i++){
        int a, b; cin >> a >> b;
        int tmp = arr[b];
        arr[b] = arr[a];
        arr[a] = tmp;
    }

    for(int i=1; i<=N; i++){
        cout << arr[i] << " ";
    }

    return 0;
}