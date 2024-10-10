#include <iostream>
#include <string>
using namespace std;

string M, N;
string cmp;

bool solve(int cur, int val, int mod)
{
    if(cur == cmp.size()){
        if(val == 0) return true;
        else return false;
    }
    if(cmp[cur] == '0'){
        if(solve(cur + 1, val * 2 % mod, mod)) return true;
    }
    else if(cmp[cur] == '1'){
        if(solve(cur + 1, (val * 2 + 1) % mod, mod)) return true;
    }
    else{
        cmp[cur] = '0';
        if(solve(cur + 1, val * 2 % mod, mod)) return true;
        cmp[cur] = '1';
        if(solve(cur + 1, (val * 2 + 1) % mod, mod)) return true;
        cmp[cur] = '*';
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int sz = M.size();
    for(int i=0; i<(1<<sz); i++){
        bool flag = true;
        for(int j=0; j<sz; j++){
            if(M[sz-j-1] != '*' && (M[sz-j-1] - '0') != ((i >> j) & 1)){
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        
        cmp = N;
        if(solve(0, 0, i)){
            cout << cmp << '\n';
            return 0;
        }
    }

    return 0;
}