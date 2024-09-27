#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string str; cin >> str;
    list<char> li;
    for(int i=0; i<str.length(); i++){
        li.push_back(str[i]);
    }

    auto iter = li.end();
    int T; cin >> T;
    while(T--){
        char op; cin >> op;
        if(op == 'L'){
            if(iter != li.begin()) iter--;
        }
        else if(op == 'D'){
            if(iter != li.end()) iter++;
        }
        else if(op == 'B'){
            if(iter != li.begin()){
                li.erase(prev(iter));
            }
        }
        else{
            char a; cin >> a;
            iter = li.insert(iter, a);
            iter++;
        }
    }
    
    for(auto x: li) cout << x;
    cout << '\n';

    return 0;
}