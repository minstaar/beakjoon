#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cstdlib>
using namespace std;
using ll = long long;

const ll MOD = 1LL << 32;
vector<bitset<35>> M(10);
bitset<35> sumM, key;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        for(int i=0; i<9; i++){
            M[i].reset();
            sumM.reset();
            key.reset();
        }
        ll sum = 0;
        for(int i=0; i<9; i++){
            string s; cin >> s;
            ll t = strtol(s.c_str(), NULL, 16);
            M[i] = bitset<35>(t);
            if(i < 8) sum = (sum + t) % MOD;
        }
        
        sumM = bitset<35>(sum);
        vector<int> cnt(35), cntN(35), cntM(35);
        for(int i=0; i<32; i++){
            for(int j=0; j<8; j++){
                cnt[i] += M[j][i];
            }
        }

        if(M[8][0] != sumM[0]){
            key[0] = 1;
            cntN[0] = 8 - cnt[0];
            cntM[0] = cnt[0];
        }
        else cntN[0] = cntM[0] = cnt[0];
        for(int i=1; i<32; i++){
            cntN[i] = cntN[i-1] / 2 + cnt[i];
            cntM[i] = cntM[i-1] / 2 + cnt[i];
            if(M[8][i] != sumM[i] && (cntN[i-1] / 2) % 2 == (cntM[i-1] / 2) % 2){
                key[i] = 1;
                cntN[i] = cntN[i-1] / 2 + 8 - cnt[i];
            }
            else if(M[8][i] == sumM[i] && (cntN[i-1] / 2) % 2 != (cntM[i-1] / 2) % 2){
                key[i] = 1;
                cntN[i] = cntN[i-1] / 2 + 8 - cnt[i];
            }
        }

        cout << hex << key.to_ullong() << '\n';
    }
}