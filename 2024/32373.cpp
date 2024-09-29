#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Data
{
    int n, idx;
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    vector<Data> sorted(N);
    for(int i=0; i<N; i++){
        cin >> sorted[i].n;
        sorted[i].idx = i;
    }
    sort(sorted.begin(), sorted.end(), [](Data a, Data b) -> bool{
        return a.n < b.n;
    });

    bool flag = true;
    for(int i=0; i<N; i++){
        if(abs(sorted[i].idx - i) % K){
            flag = false;
            break;
        }
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}