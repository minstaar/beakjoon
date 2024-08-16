#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    priority_queue<int, vector<int>, greater<>> pq;
    int N; cin >> N;
    int res = 0;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        pq.push(a);
    }
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        res += a + b;
        pq.push(a + b);
    }
    cout << res << '\n';

    return 0;
}