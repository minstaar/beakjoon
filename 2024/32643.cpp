#include <iostream>
#include <cstring>
using namespace std;

bool prime[5000010];
int psum[5000010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    for(int i=2; i*i<=N; i++){
        if(!prime[i]) continue;
        for(int j=i+i; j<=N; j+=i) prime[j] = false;
    }
    for(int i=1; i<=N; i++) psum[i] += psum[i-1] + prime[i];

    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        cout << psum[b] - psum[a-1] << '\n';
    }

    return 0;
}