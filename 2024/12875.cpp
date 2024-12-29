#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, D;
vector<vector<int>> dist(60, vector<int>(60, 1e9));

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> D;
    for(int i=0; i<N; i++){
        string str; cin >> str;
        for(int j=0; j<N; j++){
            if(str[j] == 'Y') dist[i][j] = 1;
        }
        dist[i][i] = 0;
    }

    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ans = max(ans, dist[i][j]);
        }
    }

    if(ans == 1e9) cout << "-1\n";
    else cout << D * ans << '\n';

    return 0;
}