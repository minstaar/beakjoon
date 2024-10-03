#include <iostream>
using namespace std;

bool arr[2][200010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<2; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    for(int i=0; i<2; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j]){
                cnt += 3;
                if(j != 0 && arr[i][j-1]) cnt--;
                if(j != N - 1 && arr[i][j+1]) cnt--;
                if(j % 2 == 0){
                    if(i == 0 && arr[i+1][j]) cnt--;
                    if(i == 1 && arr[i-1][j]) cnt--;
                }
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}