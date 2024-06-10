#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string str; cin >> str;
    string res;
    bool flag = true;
    for(int i=0; i<str.length();){
        if(str[i] == 'Z' && str.substr(i, 4) == "ZERO"){
            res.push_back('0');
            i += 4;
        }
        else if(str[i] == 'O' && str.substr(i, 3) == "ONE"){
            res.push_back('1');
            i += 3;
        }
        else if(str[i] == 'T' && str.substr(i, 3) == "TWO"){
            res.push_back('2');
            i += 3;
        }    
        else if(str[i] == 'T' && str.substr(i, 5) == "THREE"){
            res.push_back('3');
            i += 5;
        }
        else if(str[i] == 'F' && str.substr(i, 4) == "FOUR"){
            res.push_back('4');
            i += 4;
        }
        else if(str[i] == 'F' && str.substr(i, 4) == "FIVE"){
            res.push_back('5');
            i += 4;
        }
        else if(str[i] == 'S' && str.substr(i, 3) == "SIX"){
            res.push_back('6');
            i += 3;
        }
        else if(str[i] == 'S' && str.substr(i, 5) == "SEVEN"){
            res.push_back('7');
            i += 5;
        }
        else if(str[i] == 'E' && str.substr(i, 5) == "EIGHT"){
            res.push_back('8');
            i += 5;
        }
        else if(str[i] == 'N' && str.substr(i, 4) == "NINE"){
            res.push_back('9');
            i += 4;
        }

        else if(str[i] == '+' || str[i] == '-' || str[i] == 'x' || str[i] == '/' || str[i] == '='){
            res.push_back(str[i]);
            i++;
        }

        else{
            flag = false;
            break;
        }
    }

    ll prev = 0, cur = 0;
    char op = 0;
    for(int i=0; i<res.length(); i++){
        if(res[i] >= '0' && res[i] <= '9'){
            cur *= 10;
            cur += res[i] - '0';
        }
        else{
            if(op == 0){
                prev = cur;
                cur = 0;
                op = res[i];
            }
            else if(res[i-1] < '0' || res[i-1] > '9'){
                flag = false;
                break;
            }
            else{
                if(op == '+'){
                    prev += cur;
                    cur = 0;
                    op = res[i];
                }
                else if(op == '-'){
                    prev -= cur;
                    cur = 0;
                    op = res[i];
                }
                else if(op == 'x'){
                    prev *= cur;
                    cur = 0;
                    op = res[i];
                }
                else{
                    prev /= cur;
                    cur = 0;
                    op = res[i];
                }
            }
        }
    }
    
    if(!flag) cout << "Madness!" << '\n';
    else{
        cout << res << '\n';
        map<int, string> m;
        m[0] = "ZERO";
        m[1] = "ONE";
        m[2] = "TWO";
        m[3] = "THREE";
        m[4] = "FOUR";
        m[5] = "FIVE";
        m[6] = "SIX";
        m[7] = "SEVEN";
        m[8] = "EIGHT";
        m[9] = "NINE";
        stack<string> st;
        if(prev < 0){
            cout << '-';
            prev = abs(prev);
        }
        else if(prev == 0){
            st.push(m[0]);
        }
        while(prev > 0){
            int t = prev % 10;
            st.push(m[t]);
            prev /= 10;
        }
        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
    }

    return 0;    
}