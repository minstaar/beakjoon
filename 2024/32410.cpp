#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N, M, X, Y, K;
vector<pii> arr, query;
int dp[310][310], psum[50010][300];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> X >> Y;
    arr.resize(N);
    for(int i=0; i<N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    cin >> K;
    query.resize(K);
    for(int i=0; i<K; i++){
        cin >> query[i].first >> query[i].second;
    }

    sort(query.begin(), query.end()); //몬스터를 공격력 기준으로 정렬
    for(int i=query[0].second; i<=300; i++) psum[0][i] = 1;
    for(int i=1; i<K; i++){
        for(int j=1; j<=300; j++){
            if(query[i].second <= j) psum[i][j] = psum[i-1][j] + 1; //0 ~ i번 까지 체력이 j 이하인 몬스터의 수 저장
            else psum[i][j] = psum[i-1][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[X][Y] = 0; //dp[i][j] = 공격력이 i, 체력이 j일 때 사용하는 장비의 최소 개수
    for(int i=0; i<N; i++){
        auto [x, y] = arr[i];
        for(int j=300; j>=X; j--){ //중복 선택 방지를 위해 역순으로 탐색
            for(int k=300; k>=Y; k--){
                if(dp[j][k] != -1){
                    int nx = min(300, j + x);
                    int ny = min(300, k + y);
                    if(dp[nx][ny] == -1 || dp[nx][ny] > dp[j][k] + 1) dp[nx][ny] = dp[j][k] + 1;
                }
            }
        }
    }

    int ans = 0;
    for(int i=X; i<=300; i++){ //공격력이 i, 체력이 j일 때 사냥할 수 있는 몬스터의 수 탐색
        for(int j=Y; j<=300; j++){
            if(dp[i][j] == -1 || dp[i][j] > M) continue;
            int idx = upper_bound(query.begin(), query.end(), make_pair(i, 300)) - query.begin() - 1;
            if(idx >= 0) ans = max(ans, psum[idx][j]);
        }
    }

    cout << ans << '\n';

    return 0;
}