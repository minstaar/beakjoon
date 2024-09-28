#include <iostream>
#include <set>
using ll = long long;
using namespace std;

int N;
ll D[200010], H[200010];
set<int> s;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> D[i];
    for(int i=1; i<=N; i++) cin >> H[i];
    for(int i=1; i<=N; i++) s.insert(i);

    ll sum = 0;
    int p = N, cnt = 0;
    while(p > 1){
        auto it = s.begin();
        while(it != s.end()){
            int i = *it;
            it++;
            if(H[i] - sum + D[i] * cnt <= 0){
                H[i] = 0;
                s.erase(i);
                p--;
            }
            else{
                sum += D[i];
            }
            if(p == 1) break;
        }
        cnt++;
    }
    for(int i=1; i<=N; i++){
        if(H[i] != 0){
            cout << i << '\n';
            break;
        }
    }

    return 0;
}