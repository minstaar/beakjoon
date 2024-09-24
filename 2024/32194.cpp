#include <iostream>
using namespace std;

int N, arr[200010], psum[200010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    arr[1] = 1, psum[1] = 1;
    for(int i=2; i<=N+1; i++){
        int op, s, e; cin >> op >> s >> e;
        if(op == 1){
            if(psum[e] - psum[s-1] == e - s + 1){
                cout << "Yes\n";
                arr[i] = 1;
                psum[i] = psum[i-1] + 1;
            }
            else{
                cout << "No\n";
                psum[i] = psum[i-1];
            }
        }
        else{
            if(psum[e] - psum[s-1] == 0){
                cout << "Yes\n";
                arr[i] = 1;
                psum[i] = psum[i-1] + 1;
            }
            else{
                cout << "No\n";
                arr[i] = 0;
                psum[i] = psum[i-1];
            }
        }
    }

    return 0;
}