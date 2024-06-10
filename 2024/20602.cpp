#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int x, y, z; cin >> x >> y >> z;
        vector<vector<char>> arr(200, vector<char>(200));

        for(int i=1; i<=y*2; i++){
            int px = 1;
            for(int j=i; j<=y*2; j++){
                arr[i][px] = '.';
                px++;
            }
            for(int j=1; j<=x*2; j++){
                if(i % 2) arr[i][px] = (j % 2 ? '+' : '-');
                else arr[i][px] = (j % 2 ? '/' : '.');
                px++;
            }
            arr[i][px] = (arr[i][px-1] == '-' ? '+' : '/');
        }

        for(int i=1; i<=z*2+1; i++){
            int py = y * 2 + i;
            for(int j=1; j<=x*2+1; j++){
                if(i % 2) arr[py][j] = (j % 2 ? '+' : '-');
                else arr[py][j] = (j % 2 ? '|' : '.');
            }
        }

        int my = y * 2 + z * 2 + 1;
        int mx = y * 2 + x * 2 + 1;
        
        for(int i=1; i<=y*2; i++){
            int px = mx - i + 1;
            int py = 1;
            for(;; py++){
                if(arr[py][px] == 0) break;
            }
            for(int j=1; j<=z*2; j++){
                if(i % 2) arr[py][px] = (arr[py-1][px] == '+' ? '|' : '+');
                else arr[py][px] = (arr[py-1][px] == '/' ? '.' : '/');
                py++;
            }
            for(int j=py; j<=my; j++){
                arr[j][px] = '.';
            }
        }

        for(int i=1; i<=my; i++){
            for(int j=1; j<=mx; j++){
                cout << arr[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}