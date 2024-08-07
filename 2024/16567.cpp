#include <iostream>
using namespace std;

int N, M, arr[1000010], flip;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        if(arr[i] && !arr[i-1]) flip++;
    }

    while(M--){
        int op; cin >> op;
        if(!op) cout << flip << '\n';
        else{
            int i; cin >> i;
            if(arr[i]) continue;
            else if(arr[i-1] && arr[i+1]) flip --;
            else if(!arr[i-1] && !arr[i+1]) flip ++;
            arr[i] = 1;
        }
    }

    return 0;
}