#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int>> arr(N + 1, vector<int>(N + 1, 1));
    while(M--){
        int x, y, op; cin >> x >> y >> op;
        if(op == 1){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(i >= x || j != y) arr[i][j] = 0;
                }
            }
        }
        if(op == 2){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(i >= x || j <= y) arr[i][j] = 0;
                }
            }
        }
        if(op == 3){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(i != x || j <= y) arr[i][j] = 0;
                }
            }
        }
        if(op == 4){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(i <= x || j <= y) arr[i][j] = 0;
                }
            }
        }
        if(op == 5){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(i <= x || j != y) arr[i][j] = 0;
                }
            }
        }
        if(op == 6){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(i <= x || j >= y) arr[i][j] = 0;
                }
            }
        }
        if(op == 7){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(i != x || j >= y) arr[i][j] = 0;
                }
            }
        }
        if(op == 8){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(i >= x || j >= y) arr[i][j] = 0;
                }
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j]) cout << i << ' ' << j << '\n';
        }
    }

    return 0;
}