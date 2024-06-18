#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<double, char> p;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    string str; cin >> str;
    map<char, double> m;
    int ans = 0, comp = 0;
    p tmp = {0, 0};
    for(int i=0; i<str.length(); i++){
        m[str[i]]++;
        if(tmp.first < m[str[i]]){
            tmp = {m[str[i]], str[i]};
        }
    }
    for(auto x: m){
        if(x.first == tmp.second){
            comp += (int)(x.second + M) * (x.second + M);
        }
        else{
            comp += (int)x.second * x.second;
        }
    }
    comp += min({(int)m['k'] / 2, (int)m['o'] / 2, (int)m['d'], (int)m['r']}) * 7;
    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({m['k'] / 2, 'k'});
    pq.push({m['o'] / 2, 'o'});
    pq.push({m['r'], 'r'});
    pq.push({m['d'], 'd'});
    for(int i=0; i<M; i++){
        p cur = pq.top();
        pq.pop();
        if(cur.second == 'k' || cur.second == 'o'){
            pq.push({cur.first + 0.5, cur.second});
        }
        else pq.push({cur.first + 1, cur.second});
    }
    int match = 1e9;
    while(!pq.empty()){
        p cur = pq.top();
        pq.pop();
        match = min((int)cur.first, match);
        if(cur.second == 'k' || cur.second == 'o'){
            ans += (int)(cur.first * 2) * (cur.first * 2);
        }
        else ans += (int)cur.first * cur.first;
    }
    ans += match * 7;
    cout << max(ans, comp) << '\n';

    return 0;
}