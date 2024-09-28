#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int px = 0, py = 0, cx = 0, cy = -1;
    int dir = 0;

    while(N--){
        string op; cin >> op;
        if(op[0] == 'W'){
            px += "1210"[dir] - '1';
            py += "2101"[dir] - '1';
            cx += "1210"[dir] - '1';
            cy += "2101"[dir] - '1';
        }
        else if(op[0] == 'D'){
            px += "1210"[(dir+1)%4] - '1';
            py += "2101"[(dir+1)%4] - '1';
            cx += "1210"[(dir+1)%4] - '1';
            cy += "2101"[(dir+1)%4] - '1';
        }
        else if(op[0] == 'S'){
            px += "1210"[(dir+2)%4] - '1';
            py += "2101"[(dir+2)%4] - '1';
            cx += "1210"[(dir+2)%4] - '1';
            cy += "2101"[(dir+2)%4] - '1';
        }
        else if(op[0] == 'A'){
            px += "1210"[(dir+3)%4] - '1';
            py += "2101"[(dir+3)%4] - '1';
            cx += "1210"[(dir+3)%4] - '1';
            cy += "2101"[(dir+3)%4] - '1';
        }
        else if(op == "MR"){
            cx += "0220"[dir] - '1';
            cy += "2200"[dir] - '1';
            dir = (dir + 1) % 4;
        }
        else{
            cx += "2200"[dir] - '1';
            cy += "2002"[dir] - '1';
            if(dir == 0) dir = 3;
            else dir--;
        }
        cout << px << ' ' << py << ' ' << cx << ' ' << cy << '\n';
    }

    return 0;
}