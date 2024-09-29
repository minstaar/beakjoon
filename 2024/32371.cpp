#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<string> arr(4);
    for(int i=0; i<4; i++) cin >> arr[i];
    string str; cin >> str;
    int px = 0, py = 0;
    for(int i=0; i<=str.length(); i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<10; k++){
                if(arr[j][k] == str[i]){
                    px += j;
                    py += k;
                }
            }
        }
    }
    cout << arr[px/9][py/9] << '\n';

    return 0;
}