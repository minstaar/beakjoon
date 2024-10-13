#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(int t=1; ; t++){
        string s; cin >> s;
        if(s == "0") break;
        while(1){
            if(s.size() % 2){
                cout << "Test " << t << ": " << s << '\n';
                break;
            }
            string next;
            bool flag = true;
            for(int i=0; i<s.size(); i+=2){
                if(next != "" && next.back() == s[i+1]){
                    flag = false;
                    break;
                }
                int k = s[i] - '0';
                for(int j=0; j<k; j++){
                    next = next + s[i+1];
                }
            }
            if(!flag){
                cout << "Test " << t << ": " << s << '\n';
                break;
            }
            if(next == s){
                cout << "Test " << t << ": " << next << '\n';
                break;
            }
            s = next;
        }
    }

    return 0;
}