#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        string s1, s2;
        cin.ignore();
        getline(cin, s1), getline(cin, s2);
        set<string> eng, fre, both;
        
        string tmp;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] == ' '){
                eng.insert(tmp);
                tmp = "";
                continue;
            }
            tmp += s1[i];
        }
        eng.insert(tmp);
        tmp = "";
        for(int i=0; i<s2.size(); i++){
            if(s2[i] == ' '){
                fre.insert(tmp);
                if(eng.find(tmp) != eng.end()) both.insert(tmp);
                tmp = "";
                continue;
            }
            tmp += s2[i];
        }
        fre.insert(tmp);
        if(eng.find(tmp) != eng.end()) both.insert(tmp);

        int ans = 0;
        for(int i=0; i<1<<(N-2); i++){
            
        }

    }

    return 0;
}