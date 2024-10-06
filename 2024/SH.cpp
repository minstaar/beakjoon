#include <iostream>
#include <string>
#include <vector>
using namespace std;

int arr[1010][1010];
vector<string> ans(1000);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int cntA = 0, cntB = 0;
    for(int i=0; i<N; i++){
        int K; cin >> K;
        for(int j=0; j<K; j++){
            cin >> arr[i][j];
        }
        for(int j=0; j<i; j++){
            for(int k=0; k<=K; k++){
                if(arr[j][k] == arr[i][k]){
                    ans[i] = "Bob";
                    cntB++;
                    break;
                }
            }
            if(ans[i] != "") break;
        }
    }
    for(int i=0; i<N; i++){
        if(ans[i] == ""){
            if(cntB > N / 2){
                cout << "Alice" << endl;
            }
            else{
                cout << "BOB" << endl;
                cntB++;
            }
        }
        else cout << ans[i] << endl;
    }

    return 0;
}