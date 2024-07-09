#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Data{int a, b, c;};
vector<Data> arr(10);

bool check(Data x, Data y, Data z)
{
    if(!(x.a == y.a && y.a == z.a) && (x.a == y.a || x.a == z.a || y.a == z.a)) return false;
    if(!(x.b == y.b && y.b == z.b) && (x.b == y.b || x.b == z.b || y.b == z.b)) return false;
    if(!(x.c == y.c && y.c == z.c) && (x.c == y.c || x.c == z.c || y.c == z.c)) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(int i=0; i<9; i++){
        string str; cin >> str;
        if(str == "CIRCLE") arr[i].a = 0;
        else if(str == "TRIANGLE") arr[i].a = 1;
        else arr[i].a = 2;

        cin >> str;
        if(str == "YELLOW") arr[i].b = 0;
        else if(str == "RED") arr[i].b = 1;
        else arr[i].b = 2;

        cin >> str;
        if(str == "GRAY") arr[i].c = 0;
        else if(str == "WHITE") arr[i].c = 1;
        else arr[i].c = 2;
    }

    int res = 0;
    bool used[1010] = {}, end = false;
    int Q; cin >> Q;
    while(Q--){
        char op; cin >> op;
        if(op == 'H'){
            int x, y, z; cin >> x >> y >> z;
            x--, y--, z--;
            int tmp = (1 << x) + (1 << y) + (1 << z);
            if(check(arr[x], arr[y], arr[z]) && !used[tmp]){
                used[tmp] = true;
                res++;
            }
            else res--;
        }
        else{
            bool flag = true;
            for(int i=0; i<7; i++){
                for(int j=i+1; j<8; j++){
                    for(int k=j+1; k<9; k++){
                        int tmp = (1 << i) + (1 << j) + (1 << k);
                        if(used[tmp]) continue;
                        if(check(arr[i], arr[j], arr[k])){
                            flag = false;
                        }
                    }
                }
            }
            if(flag && !end){
                end = true;
                res += 3;
            }
            else res--;
        }
    }
    cout << res << '\n';
    
    return 0;
}