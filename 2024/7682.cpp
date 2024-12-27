#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string str;
    while(1){
        cin >> str;
        if(str == "end") break; 
        int cntO = 0, cntX = 0;
        int rowO[3] = {}, colO[3] = {}, rowX[3] = {}, colX[3] = {};
        for(int i=0; i<str.size(); i++){
            if(str[i] == 'O'){
                rowO[i/3]++;
                colO[i%3]++;
                cntO++;
            }
            else if(str[i] == 'X'){
                rowX[i/3]++;
                colX[i%3]++;
                cntX++;
            }
        }

        if(cntO + 1 != cntX && cntO != cntX){
            cout << "invalid\n";
            continue;
        }

        if(rowX[0] == 3 || rowX[1] == 3 || rowX[2] == 3 || colX[0] == 3 || colX[1] == 3 || colX[2] == 3 || (str[0] == 'X' && str[4] == 'X' && str[8] == 'X') || (str[2] == 'X' && str[4] == 'X' && str[6] == 'X')){
            if(cntO + 1 == cntX && rowO[0] != 3 && rowO[1] != 3 && rowO[2] != 3 && colO[0] != 3 && colO[1] != 3 && colO[2] != 3 && !(str[0] == 'O' && str[4] == 'O' && str[8] == 'O') && !(str[2] == 'O' && str[4] == 'O' && str[6] == 'O')){
                cout << "valid\n";
            }
            else cout << "invalid\n";
        }

        else if(rowO[0] == 3 || rowO[1] == 3 || rowO[2] == 3 || colO[0] == 3 || colO[1] == 3 || colO[2] == 3 || (str[0] == 'O' && str[4] == 'O' && str[8] == 'O') || (str[2] == 'O' && str[4] == 'O' && str[6] == 'O')){
            if(cntO == cntX && rowX[0] != 3 && rowX[1] != 3 && rowX[2] != 3 && colX[0] != 3 && colX[1] != 3 && colX[2] != 3 && !(str[0] == 'X' && str[4] == 'X' && str[8] == 'X') && !(str[2] == 'X' && str[4] == 'X' && str[6] == 'X')){
                cout << "valid\n";
            }
            else cout << "invalid\n";
        }

        else if(cntO + cntX == 9) cout << "valid\n";

        else cout << "invalid\n";
    }

    return 0;
}