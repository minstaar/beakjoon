#include <bits/stdc++.h>
using namespace std;

int arr[2050];
int cmp[2050];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++){
        arr[i] = i;
        cmp[i] = N - i - 1;
    }
    do{
        bool flag = true;
        for(int i=0; i<N; i++){
            if((arr[i] & cmp[i]) != 0){
                flag = false;
                break;
            }
        }
        if(flag){
            for(int i=0; i<N; i++) cout << cmp[i] << ' ';
            cout << '\n';
            break;
        }
    }while(prev_permutation(cmp, cmp+N));


    return 0;
}