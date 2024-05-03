#include <iostream>
#define MAX 22
using namespace std;

int arr[200010], table[MAX][200010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int M; cin >> M;
    for(int i=1; i<=M; i++){
        cin >> arr[i];
    }
    for(int i=1; i<=M; i++){
        table[i][0] = arr[i];
    }
    for(int i=1; i<MAX; i++){
        for(int j=1; j<=M; j++){
            int tmp = table[j][i-1];
            table[j][i] = table[tmp][i-1];
        }
    }
    int Q; cin >> Q;
    while(Q--){
        int n, x; cin >> n >> x;
        x = arr[x];
        n--;
        for(int i=0; n; i++){
            if(n % 2) x = table[x][i];
            n /= 2;
        }
        cout << x << '\n';
    }

    return 0;
}