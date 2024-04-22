#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;

void dfs(int cnt, int arr[][25])
{
    if(cnt >= 5){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                ans = max(ans, arr[i][j]);
            }
        }
        return;
    }

    int copy[25][25];
    bool check = false;

    //up
    bool flag = false;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            copy[i][j] = arr[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                if(copy[j][i] == copy[k][i]){
                    copy[j][i] += copy[k][i];
                    copy[k][i] = 0;
                    check = flag = true;
                    break;
                }
                else if(copy[k][i] != 0) break;
            }
            for(int k=j-1; k>=0; k--){
                if(copy[k][i] == 0){
                    copy[k][i] = copy[k+1][i];
                    copy[k+1][i] = 0;
                    check = flag = true;
                }
                else break;
            }
        }
        for(int j=N-2; j>=0; j--){
            if(copy[j][i] == 0){
                copy[j][i] = copy[j+1][i];
                copy[j+1][i] = 0;
                check = flag = true;
            }
            else break;
        }
    }
    if(flag) dfs(cnt + 1, copy);
    
    //down
    flag = false;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            copy[i][j] = arr[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=N-1; j>=1; j--){
            for(int k=j-1; k>=0; k--){
                if(copy[j][i] == copy[k][i]){
                    copy[j][i] += copy[k][i];
                    copy[k][i] = 0;
                    check = flag = true;
                    break;
                }
                else if(copy[k][i] != 0) break;
            }
            for(int k=j+1; k<N; k++){
                if(copy[k][i] == 0){
                    copy[k][i] = copy[k-1][i];
                    copy[k-1][i] = 0;
                    check = flag = true;
                }
                else break;
            }
        }
        for(int j=1; j<N; j++){
            if(copy[j][i] == 0){
                copy[j][i] = copy[j-1][i];
                copy[j-1][i] = 0;
                check = flag = true;
            }
            else break;
        }
    }
    if(flag) dfs(cnt + 1, copy);

    //left
    flag = false;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            copy[i][j] = arr[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                if(copy[i][j] == copy[i][k]){
                    copy[i][j] += copy[i][k];
                    copy[i][k] = 0;
                    check = flag = true;
                    break;
                }
                else if(copy[i][k] != 0) break;
            }
            for(int k=j-1; k>=0; k--){
                if(copy[i][k] == 0){
                    copy[i][k] = copy[i][k+1];
                    copy[i][k+1] = 0;
                    check = flag = true;
                }
                else break;
            }
        }
        for(int j=N-2; j>=0; j--){
            if(copy[i][j] == 0){
                copy[i][j] = copy[i][j+1];
                copy[i][j+1] = 0;
                check = flag = true;
            }
            else break;
        }
    }
    if(flag) dfs(cnt + 1, copy);

    //right
    flag = false;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            copy[i][j] = arr[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=N-1; j>=1; j--){
            for(int k=j-1; k>=0; k--){
                if(copy[i][j] == copy[i][k]){
                    copy[i][j] += copy[i][k];
                    copy[i][k] = 0;
                    check = flag = true;
                    break;
                }
                else if(copy[i][k] != 0) break;
            }
            for(int k=j+1; k<N; k++){
                if(copy[i][k] == 0){
                    copy[i][k] = copy[i][k-1];
                    copy[i][k-1] = 0;
                    check = flag = true;
                }
                else break;
            }
        }
        for(int j=1; j<N; j++){
            if(copy[i][j] == 0){
                copy[i][j] = copy[i][j-1];
                copy[i][j-1] = 0;
                check = flag = true;
            }
            else break;
        }
    }
    if(flag) dfs(cnt + 1, copy);

    if(!check){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                ans = max(ans, arr[i][j]);
            }
        }
        return;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int arr[25][25];
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    dfs(0, arr);
    cout << ans << '\n';

    return 0;
}