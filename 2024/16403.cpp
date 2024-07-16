#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
bool check[100010];
queue<int> arr, cmp;
vector<int> res;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<M; i++){
        int a; cin >> a;
        arr.push(a);
        check[a] = true;
    }
    for(int i=1; i<=N; i++){
        if(!check[i]) cmp.push(i);
    }
    for(int i=0; i<N; i++){
        if(arr.empty()){
            res.push_back(cmp.front());
            cmp.pop();
        }
        else if(cmp.empty()){
            res.push_back(arr.front());
            arr.pop();
        }
        else if(arr.front() > cmp.front()){
            res.push_back(cmp.front());
            cmp.pop();
        }
        else{
            res.push_back(arr.front());
            arr.pop();
        }
    }
    for(auto x: res) cout << x << '\n';

    return 0;
}