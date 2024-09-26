#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    if(N == 1) cout << "N\n";
    else if(N == 2) cout << "Y\n";
    else{
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<N; i++){
            int a; cin >> a;
            pq.push(a);
        }
        bool flag = false;
        while(pq.size() >= 2){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if(a == b) pq.push(a + 1);
            else{
                if(!flag){
                    flag = true;
                    pq.push(b);
                }
                else{
                    cout << "N\n";
                    return 0;
                }
            }
        }
        cout << "Y\n";
    }

    return 0;
}