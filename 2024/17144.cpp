#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Data{
    int y;
    int x;
    int value;
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int r, c, t; cin>>r>>c>>t;
    int sum = 0;
    vector<vector<int>> arr(r, vector<int>(c));
    stack<Data> dust;
    int air1 = 0, air2 = 0;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[i][j];
            if(arr[i][j] == -1){
                air1 == 0 ? air1 = i : air2 = i;
            }
            else if(arr[i][j] > 0){
                dust.push({i, j, arr[i][j]});
                sum += arr[i][j];
            }
        }
    }

    while(t--){
        int dy[4] = {-1, 1, 0, 0};
        int dx[4] = {0, 0, -1, 1};
        while(!dust.empty()){
            Data cur = dust.top();
            dust.pop();
            for(int i=0; i<4; i++){
                int y = cur.y + dy[i];
                int x = cur.x + dx[i];
                if(y < 0 || x < 0 || y >= r || x >= c || arr[y][x] == -1) continue;
                arr[y][x] += cur.value / 5;
                arr[cur.y][cur.x] -= cur.value / 5;
            }
        }

        int tmp1 = 0;
        int tmp2;
        for(int i=1; i<c; i++){
            tmp2 = arr[air1][i];
            arr[air1][i] = tmp1;
            tmp1 = tmp2;
        }
        for(int i=air1-1; i>=0; i--){
            tmp2 = arr[i][c-1];
            arr[i][c-1] = tmp1;
            tmp1 = tmp2;
        }

        for(int i=c-2 ; i>=0; i--){
            tmp2 = arr[0][i];
            arr[0][i] = tmp1;
            tmp1 = tmp2;
        }

        for(int i=1; i<air1; i++){
            tmp2 = arr[i][0];
            arr[i][0] = tmp1;
            tmp1 = tmp2;
        }
        sum -= tmp1;

        tmp1 = 0;
        for(int i=1; i<c; i++){
            tmp2 = arr[air2][i];
            arr[air2][i] = tmp1;
            tmp1 = tmp2;
        }
        for(int i=air2+1; i<r; i++){
            tmp2 = arr[i][c-1];
            arr[i][c-1] = tmp1;
            tmp1 = tmp2;
        }
        for(int i=c-2 ; i>=0; i--){
            tmp2 = arr[r-1][i];
            arr[r-1][i] = tmp1;
            tmp1 = tmp2;
        }
        for(int i=r-2; i>air2; i--){
            tmp2 = arr[i][0];
            arr[i][0] = tmp1;
            tmp1 = tmp2;
        }
        sum -= tmp1;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(arr[i][j] > 0){
                    dust.push({i, j, arr[i][j]});
                }
            }
        }
    }

    cout<<sum;
    
    return 0;
}
