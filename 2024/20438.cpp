#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, K, Q, M;
int arr[5010], psum[5010];
set<int> s;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K >> Q >> M;
    fill(arr, arr + N + 3, 1);
    for(int i=0; i<K; i++){
        int a; cin >> a;
        s.insert(a);
    }
    
    for(int i=0; i<Q; i++){
        int a; cin >> a;
        if(s.find(a) != s.end()) continue;
        for(int j=a; j<=N+2; j+=a){
            if(s.find(j) != s.end()) continue;
            arr[j] = 0;
        }
    }
    for(int i=1; i<=N+2; i++) psum[i] = psum[i-1] + arr[i];

    for(int i=0; i<M; i++){
        int s, e; cin >> s >> e;
        cout << psum[e] - psum[s-1] << '\n';
    }

    return 0;
}