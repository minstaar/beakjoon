#include <iostream>
#include <vector>
using namespace std;

int B, X, N;
int arr[288010][10];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> B >> X >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<9; j++){
            cin >> arr[i][j];
        }
    }

    double unit = 60 / B; 
    int res = 0;
    for(int i=0; i<9; i++){
        int cnt = 0;
        bool state = false;
        for(int j=N-1; j>=0; j--){
            if(arr[j][i] == 0) continue;
            if(arr[j][i] == 2){
                if((j == N - 1 && arr[j-1][i] != 0) || (j != N - 1 && arr[j+1][i] == 0)){
                    state = true;
                    res += cnt * 100;
                    res += 80;
                    cnt = 1;
                }
                else{
                    state = false;
                    cnt++;
                    res += cnt * X / 6;
                    cnt = 0;
                }
            }
            else cnt++;
        }
        if(state){
            res += cnt * X / 6;
        }
        else res += cnt * 100;
    }
    cout << res << '\n';

    return 0;
}