#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    map<int, int> m;
    int N, M, K; cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        int key, value; cin >> key >> value;
        m[key] = value;
    }

    while(M--){
        int op; cin >> op;
        if(op == 1){
            int key, value; cin >> key >> value;
            m[key] = value;
        }
        else if(op == 2){
            int key, value; cin >> key >> value;
            auto it = m.lower_bound(key);
            if(it == m.begin()){
                if(abs(it->first - key) <= K) m[it->first] = value;
            }
            else if(it == m.end()){
                if(abs((--it)->first - key) <= K) m[it->first] = value;
            }
            else{
                auto it2 = prev(it);
                if(abs(it->first - key) < abs(it2->first - key)){
                    if(abs(it->first - key) <= K) m[it->first] = value;
                }
                else if(abs(it->first - key) > abs(it2->first - key)){
                    if(abs(it2->first - key) <= K) m[it2->first] = value;
                }
            }
        }
        else{
            int key; cin >> key;
            auto it = m.lower_bound(key);
            if(it == m.begin()){
                if(abs(it->first - key) <= K) cout << it->second << '\n';
                else cout << "-1\n";
            }
            else if(it == m.end()){
                if(abs((--it)->first - key) <= K) cout << it->second << '\n';
                else cout << "-1\n";
            }
            else{
                auto it2 = prev(it);
                if(abs(it->first - key) < abs(it2->first - key)){
                    if(abs(it->first - key) <= K) cout << it->second << '\n';
                    else cout << "-1\n";
                }
                else if(abs(it->first - key) > abs(it2->first - key)){
                    if(abs(it2->first - key) <= K) cout << it2->second << '\n';
                    else cout << "-1\n";
                }
                else cout << "?\n";
            }
        }
    }

    return 0;
}