#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int cnt = 0, k = 0;
        for(int i=0; i<N; i++){
            string str;
            cin >> str;
            if(i >= 1){
                if(str == "111"){
                    cnt += 2, k++;
                }
                else if(str == "110" || str == "011"){
                    cnt += 1;
                }
            }
        }
        if(cnt % 2) cout << "Yesyes\n";
        else if(k % 2) cout << "Yesyes\n";
        else cout << "Nono\n";
    }

    return 0;
}