#include <iostream>
#include <set>
#include <map>
using namespace std;
using pii = pair<int, int>;

int N, Q;
set<int> rs;
map<int, int> m;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> Q;
    for(int i=1; i<=N; i++) rs.insert(i);
    for(int i=1; i<=Q; i++){
        int op, val; cin >> op >> val;
        if(op == 1){
            if(rs.find(val) != rs.end()){
                rs.erase(val);
                m[val] = i;
                cout << val << '\n';
            }
            else{
                auto it = rs.lower_bound(val);
                if(it == rs.end()) cout << "-1\n";
                else{
                    cout << *it << '\n';
                    m[*it] = i;
                    rs.erase(it);
                }
            }
        }
        else{
            if(rs.find(val) != rs.end()){
                cout << "-1\n";
            }
            else{
                cout << m[val] << '\n';
                m.erase(val);
                rs.insert(val);
            }
        }
    }

    return 0;
}