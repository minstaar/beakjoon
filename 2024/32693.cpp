#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int arr[510][510];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<string> str(N);
    for(int i=0; i<N; i++) cin >> str[i];

    ll res = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int l = j, r = j + 1;
            while(l >= 0 && r < M){
                if(str[i][l] == str[i][r]) arr[i][j]++;
                else break;
                l--, r++;
            }
            res += arr[i][j];
        }
    }

    for(int i=0; i<N-1; i++){
        for(int j=0; j<M; j++){
            int t = arr[i][j];
            for(int k=i+1; k<N; k++){
                t = min(t, arr[k][j]);
                if(t == 0) break;
                res += t;
            }
        }
    }
    cout << res << '\n';

    return 0;
}