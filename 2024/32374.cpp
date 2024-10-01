#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    vector<int> A(N);
    map<int, int> B;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++){
        int a; cin >> a;
        B[a]++;
    }
    for(int i=0; i<K; i++){
        int a; cin >> a;
        if(B[a] == 1) B.erase(a);
        else B[a]--;
    }
    int val = prev(B.end())->first;
    sort(A.begin(), A.end());
    auto it = upper_bound(A.begin(), A.end(), val);
    it--;
    cout << *it << '\n';

    return 0;
}