#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(1){
        string str; getline(cin, str);
        if(str == "#") break;
        int cnt = 0;
        for(int i=0; i<str.size(); i++){
            if(str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U') cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}