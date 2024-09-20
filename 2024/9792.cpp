#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Data{
    int H[1510];
    int s, e;
    string str;
}arr[20];

const int P = 31, MOD = 1e4 + 7;
int prep[1510];
vector<int> hashtable[10100];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    prep[0] = 1;
    for(int i=1; i<=1500; i++){
        prep[i] = (prep[i-1] * P) % MOD;
    }
    for(int i=0; i<N; i++){
        cin >> arr[i].str;

        int len = arr[i].str.length();
        arr[i].H[0] = arr[i].str[0] - 'a';
        for(int j=1; j<len; j++){
            arr[i].H[j] = (arr[i].H[j-1] * P + arr[i].str[j] - 'a') % MOD;
        }
        for(int k=len-1; k>=2; k--){
            bool chk = false;
            for(int j=0; j<=10010; j++) hashtable[j].clear();
            for(int j=0; j<=len-k; j++){
                int hash;
                if(j != 0) hash = (arr[i].H[j+k-1] - arr[i].H[j-1] * prep[k]) % MOD;
                else hash = arr[i].H[j+k-1];
                hash = (hash + MOD) % MOD;
                if(hashtable[hash].size()){
                    bool flag = true;
                    for(auto idx: hashtable[hash]){
                        for(int l=0; l<k; l++){
                            if(arr[i].str[j+l] != arr[i].str[idx+l]){
                                flag = false;
                                break;
                            }
                        }
                        if(flag){
                            arr[i].s = idx;
                            arr[i].e = idx + k - 1;
                            chk = true;
                            break;
                        }
                    }
                }
                hashtable[hash].push_back(j);
            }
            if(chk) break;
        }
    }

    int Q; cin >> Q;
    while(Q--){
        vector<int> ans;
        string s; cin >> s;
        int comp = 0, len = s.length();
        for(int i=0; i<len; i++){
            comp = (comp * P + s[i] - 'a') % MOD;
        }
        for(int i=0; i<N; i++){
            for(int j=arr[i].s; j<=arr[i].e-len+1; j++){
                int cur;
                if(j != 0) cur = (arr[i].H[j+len-1] - arr[i].H[j-1] * prep[len]) % MOD;
                else cur = arr[i].H[j+len-1];
                cur = (cur + MOD) % MOD;
                if(cur == comp){
                    bool flag = true;
                    for(int l=0; l<len; l++){
                        if(arr[i].str[j+l] != s[l]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        ans.push_back(i);
                        break;
                    }
                }
            }
        }
        if(ans.size() == 0) cout << "-1\n";
        else{
            for(auto x: ans) cout << x << ' ';
            cout << '\n';
        }
    }

    return 0;
}