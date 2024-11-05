#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N, M, K;
vector<pii> arr(1010);
map<pii, int> m;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for(int i=0; i<N; i++) cin >> arr[i].first >> arr[i].second;

    for(int i=0; i<K; i++){
        for(int j=0; j<N; j++){
            int x, y = arr[j].second;
            if(i % 2 == 0) x = i * M + arr[j].first;
            else x = (i + 1) * M - arr[j].first;
            int g = __gcd(x, y);
            m[{x/g, y/g}]++;
        }
    }

    auto it = max_element(m.begin(), m.end(), [](const auto &x, const auto &y){
        return x.second < y.second;
    });
    cout << it->second << '\n';

    return 0;
}