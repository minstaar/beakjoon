#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int M, N; cin >> M >> N;
    vector<string> arr(5 * M + 1);
    for(int i=0; i<5*M+1; i++) cin >> arr[i];

    int res[5] = {};
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            int x = 5 * i + 1, y = 5 * j + 1;
            int k;
            for(k=0; k<4; k++) if(arr[x+k][y] == '.') break;
            res[k]++;
        }
    }

    for(int i=0; i<5; i++) cout << res[i] << ' ';

    return 0;
}