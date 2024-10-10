#include <iostream>
using namespace std;

int N, arr[55][55], tmp[55][55];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<4; i++){
        bool flag = true;
        for(int j=0; j<N-1; j++){
            for(int k=0; k<N-1; k++){
                if(arr[j][k] >= arr[j][k+1] || arr[j][k] >= arr[j+1][k]){
                    flag = false;
                }
            }
        }
        if(flag){
            cout << i << '\n';
            break;
        }
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                tmp[N-k-1][j] = arr[j][k];
            }
        }
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                arr[j][k] = tmp[j][k];
            }
        }
    }

    return 0;
}