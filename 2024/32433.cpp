#include <iostream>
using namespace std;

int N, cnt[35];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        int x; cin >> x;
        for(int j=0; j<=32; j++){
            if(x & (1 << j)) cnt[j]++;
        }
    }
    for(int i=0; i<N; i++){
        int res = 0;
        for(int j=0; j<=32; j++){
            if(cnt[j]){
                res |= (1 << j);
                cnt[j]--;
            }
        }
        cout << res << ' ';
    }

    return 0;
}