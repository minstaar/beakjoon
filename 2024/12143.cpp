#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for(int t=1; t<=T; t++){
        int N; cin >> N;
        vector<string> str[N];
        cin.ignore();
        for(int i=0; i<N; i++){
            string input, tmp;
            getline(cin, input);
            for(int j=0; j<input.size(); j++){
                if(input[j] == ' '){
                    str[i].push_back(tmp);
                    tmp = "";
                }
                tmp += input[j];
            }
            str[i].push_back(tmp);
        }
        int ans = 1e9;
        set<string> eng0, fre0;
        for(int i=0; i<str[0].size(); i++){
            eng0.insert(str[0][i]);
        }
        for(int i=0; i<str[1].size(); i++){
            fre0.insert(str[1][i]);
        }
        for(int i=0; i<(1<<(N-2)); i++){
            vector<string> eng, fre;
            for(int j=0; j<(N-2); j++){
                for(int k=0; k<str[j+2].size(); k++){
                    if((i >> j) & 1) eng.push_back(str[j+2][k]);
                    else fre.push_back(str[j+2][k]);
                }
            }
            sort(eng.begin(), eng.end()); eng.erase(unique(eng.begin(), eng.end()), eng.end());
            sort(fre.begin(), fre.end()); fre.erase(unique(fre.begin(), fre.end()), fre.end());
            int cnt = 0;
            for(auto word: fre0){
                if(eng0.find(word) != eng0.end()) cnt++;
                else if(eng.find(word) != eng.end()) cnt++;
            }
            for(auto word: fre){
                if(fre0.find(word) != fre0.end()) continue;
                if(eng0.find(word) != eng0.end()) cnt++;
                else if(eng.find(word) != eng.end()) cnt++;
            }
            ans = min(ans, cnt);
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }

    return 0;
}