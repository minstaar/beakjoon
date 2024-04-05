#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin>>T;
    while(T--){
        int a, b; cin>>a>>b;
        queue<pair<int, string>> que;
        vector<bool> check(10000);
        que.push(make_pair(a, ""));
        check[a] = true;

        while(!que.empty()){
            int n = que.front().first;
            string str = que.front().second;
            if(n == b){
                cout<<str;
                break;
            }
            que.pop();
            
            int t;
            t = n * 2 % 10000;
            if(!check[t]){
                que.push(make_pair(t, str+'D'));
                check[t] = true;
            }

            t = (n == 0) ? 9999 : n - 1;
            if(!check[t]){
                que.push(make_pair(t, str+'S'));
                check[t] = true;
            }

            t = (n == 0) ? 0 : (n % 1000) * 10 + (n / 1000);
            if(!check[t]){
                que.push(make_pair(t, str+'L'));
                check[t] = true;
            }

            t = (n == 0) ? 0 : (n / 10) + (n % 10) * 1000;
            if(!check[t]){
                que.push(make_pair(t, str+'R'));
                check[t] = true;
            }
        }
        cout<<'\n';
    }

    return 0;
}
