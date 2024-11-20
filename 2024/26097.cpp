#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
using namespace std;
using pii = pair<int, int>;

int N, M, arr[1010][1010];
bool used[1010][1010];
deque<pii> deq;

void get_adj(int x, int y)
{
    for(int i=0; i<4; i++){
        int nx = x + "1210"[i] - '1';
        int ny = y + "2101"[i] - '1';
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if(!used[nx][ny]){
            used[nx][ny] = true;
            if(arr[nx][ny]) deq.push_front({nx, ny});
            else deq.push_back({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    vector<tuple<int, int, int, int>> res;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int x = i, y = j;
            for(int k=0; k<4; k++){
                int nx = x + "1210"[k] - '1';
                int ny = y + "2101"[k] - '1';
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if(arr[x][y] & arr[nx][ny]){
                    res.push_back({x, y, nx, ny});
                    used[x][y] = used[nx][ny] = true;
                    get_adj(x, y);
                    get_adj(nx, ny);
                    break;
                }
            }
            if(res.size()) break;
        }
        if(res.size()) break;
    }

    if(res.empty()){
        cout << "-1\n";
        return 0;
    }

    while(deq.size() > 1){
        auto [x1, y1] = deq.front();
        auto [x2, y2] = deq.back();
        deq.pop_front(), deq.pop_back();
            
        if(deq.size() == 0){
            if(arr[x1][y1] ^ arr[x2][y2]){
                cout << "-1\n";
                return 0;
            }
            else{
                res.push_back({x1, y1, x2, y2});
                break;
            }
        }

        if(arr[x1][y1] == arr[deq.front().first][deq.front().second]){
            auto [x3, y3] = deq.front();
            deq.pop_front();
            deq.push_back({x2, y2});
            res.push_back({x1, y1, x3, y3});
            used[x1][y1] = used[x3][y3] = true;
            get_adj(x1, y1);
            get_adj(x3, y3);
        }
        else{
            auto [x3, y3] = deq.back();
            deq.pop_back();
            deq.push_front({x1, y1});
            res.push_back({x2, y2, x3, y3});
            used[x2][y2] = used[x3][y3] = true;
            get_adj(x2, y2);
            get_adj(x3, y3);
        }
    }

    if(deq.size() == 1){
        cout << "-1\n";
        return 0;
    }

    cout << "1\n";
    for(auto [x1, y1, x2, y2]: res){
        cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << '\n';
    }

    return 0;
}