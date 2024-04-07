#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct sharkData{
    int y;
    int x;
    int value;
    int eat;
};

struct Data{
    int y;
    int x;
    int time;

    bool operator < (const Data& other)const{
        if(time == other.time){
            if(y == other.y) return x > other.x;
            return y > other.y;
        }
        return time > other.time;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    vector<vector<int>> arr(n, vector<int>(n));
    sharkData shark;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 9){
                shark = {i, j, 2, 0};
                arr[i][j] = 0;
            }
        }
    }

    int cnt = 0;
    while(1){
        bool flag = false;
        priority_queue<Data> pq;
        pq.push({shark.y, shark.x, 0});
        vector<vector<bool>> visited(n, vector<bool>(n));
        while(!pq.empty() && !flag){
            Data cur = pq.top();
            pq.pop();
            if(arr[cur.y][cur.x] > 0 && shark.value > arr[cur.y][cur.x]){
                shark.y = cur.y;
                shark.x = cur.x;
                if(shark.eat +1 == shark.value){
                    shark.value++;
                    shark.eat = 0;
                }
                else shark.eat++;

                arr[cur.y][cur.x] = 0;
                cnt += cur.time;
                flag = true;
                break;
            }
            int dy[4] = {-1, 0, 0, 1};
            int dx[4] = {0, -1, 1, 0};
            for(int i=0; i<4; i++){
                int y = cur.y + dy[i];
                int x = cur.x + dx[i];
                if(y < 0 || x < 0 || y >= n || x >= n || shark.value < arr[y][x] || visited[y][x]) continue;
                visited[y][x] = true;
                pq.push({y, x, cur.time+1});
            }
        }
        if(!flag){
            cout<<cnt;
            break;
        }
    }

    return 0;
}
