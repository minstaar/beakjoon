#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

ll N, Q;
ll arr[300010];
vector<pair<char, int>> res;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> Q;
    for(int i=1; i<=Q; i++) cin >> arr[i];
    
    if(arr[1] != N){
        cout << -1;
        return 0;
    }

    ll r = 0, c = 0;
    for(int i=1; i<=Q; i++){
        if(abs(arr[i] - arr[i-1]) == abs(N - 2 * c)){
            if(arr[i] > arr[i-1]){ //increase
                if(c > N / 2 && r != 0) res.push_back({'R', r--});
                else if(c <= N / 2 && r != N) res.push_back({'R', ++r});
                else{
                    cout << -1;
                    return 0;
                }
            }
            else{ //decrease
                if(c > N / 2 && r != N) res.push_back({'R', ++r});
                else if(c <= N / 2 && r != 0) res.push_back({'R', r--});
                else{
                    cout << -1;
                    return 0;
                }
            }
        }

        else if(abs(arr[i] - arr[i-1]) == abs(N - 2 * r)){
            if(arr[i] > arr[i-1]){ //increase
                if(r > N / 2 && c != 0) res.push_back({'C', c--});
                else if(r <= N / 2 && c != N) res.push_back({'C', ++c});
                else{
                    cout << -1;
                    return 0;
                }
            }
            else{ //decrease
                if(r > N / 2 && c != N) res.push_back({'C', ++c});
                else if(r <= N / 2 && c != 0) res.push_back({'C', c--});
                else{
                    cout << -1;
                    return 0;
                }
            }
        }

        else{
            cout << -1;
            return 0;
        }
    }

    for(int i=0; i<Q; i++){
        cout << res[i].first << ' ' << res[i].second << '\n';
    }

    return 0;
}