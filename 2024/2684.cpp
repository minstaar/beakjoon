#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        string s; cin >> s;
        vector<int> res(8);
        for(int i=0; i<s.length()-2; i++){
            string sub = s.substr(i, 3);
            if(sub == "TTT") res[0]++;
            else if(sub == "TTH") res[1]++;
            else if(sub == "THT") res[2]++;
            else if(sub == "THH") res[3]++;
            else if(sub == "HTT") res[4]++;
            else if(sub == "HTH") res[5]++;
            else if(sub == "HHT") res[6]++;
            else if(sub == "HHH") res[7]++;
        }
        for(int i=0; i<8; i++) cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}