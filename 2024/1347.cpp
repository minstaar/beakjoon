#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool visited[110][110];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    string str; cin >> str;
    
    int x = 50, y =  50;
    int minX = 50, minY = 50;
    int maxX = 50, maxY = 50;
    int dir = 0;

    visited[x][y] = true;
    for(int i=0; i<N; i++){
        if(str[i] == 'R'){
            dir = (dir + 1) % 4;
        }
        else if(str[i] == 'L'){
            dir = (dir + 3) % 4;
        }
        else{
            x += "2101"[dir] - '1';
            y += "1012"[dir] - '1';
            visited[x][y] = true;
            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, x);
            maxY = max(maxY, y);
        }
    }

    for(int i=minX; i<=maxX; i++){
        for(int j=minY; j<=maxY; j++){
            cout << (visited[i][j] ? '.' : '#');
        }
        cout << '\n';
    }

    return 0;
}