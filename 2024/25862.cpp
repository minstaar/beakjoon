#include <iostream>
using namespace std;

const int MAX = 2e6;
int mnfactor[2000010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    for(int i=2; i<=MAX; i++){
        if(mnfactor[i] == 0){
            for(int j=i*2; j<=MAX; j+=i){
                if(mnfactor[j] == 0) mnfactor[j] = i;
            }
        }
    }
    int cnt = 0;
    for(int i=N*N; i<=MAX; i++){
        if(mnfactor[i] > N){
            cnt++;
            if(cnt == K){
                cout << i << '\n';
                break;
            }
        }
    }
    
    return 0;
}