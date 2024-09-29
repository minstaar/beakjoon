#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int N, Q;
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

    int r = 0, c = 0;
    for(int i=1; i<=Q; i++){
        if(arr[i] - arr[i-1] == N){
            if(arr[i-1] % N != 0){
                cout << -1;
                return 0;
            }
            if(r == N){
                res.push_back({'C', c});
                c--;
            }
            else{
                c++;
                res.push_back({'C', c});
            }
        }
        else if(arr[i-1] - arr[i] == N){
            if(arr[i-1] % N != 0){
                cout << -1;
                return 0;
            }
            if(r == N){
                c++;
                res.push_back({'C', c});
            }
            else{
                res.push_back({'C', c});
                c--;
            }
        }

        else if(arr[i] - arr[i-1] == N - 2 * c){
            if(r == N){
                cout << -1;
                return 0;
            }
            r++;
            res.push_back({'R', r});
        }
        else if(arr[i] - arr[i-1] == N - 2 * r){
            if(c == N){
                cout << -1;
                return 0;
            }
            c++;
            res.push_back({'C', c});
        }

        else if(arr[i-1] - arr[i] == N - 2 * c){
            if(r == 0){
                cout << -1;
                return 0;
            }
            res.push_back({'R', r});
            r--;
        }
        else if(arr[i-1] - arr[i] == N - 2 * r){
            if(c == 0){
                cout << -1;
                return 0;
            }
            res.push_back({'C', c});
            c--;
        }

        else{
            cout << -1;
            return 0;
        }
    }

    for(int i=0; i<Q; i++){
        cout << res[i].first << res[i].second << '\n';
    }

    return 0;
}