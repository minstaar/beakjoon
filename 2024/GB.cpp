#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x)
{
    if(x == 1) return false;
    for(int i=2; i*i<=x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<int> res;
    for(int i=1; i<=2000000; i++){
        if(isPrime(i)) continue;
        res.clear();
        res.push_back(i);
        for(int j=2; j<=N; j++){
            if(i + M * (j - 1) > 2000000 || isPrime(i + M * (j - 1))) break;
            res.push_back(i + M * (j - 1));
        }
        if(res.size() == N){
            for(auto x: res) cout << x << ' ';
            break;
        }
    }
    if(res.size() == 0) cout << "-1\n";

    return 0;
}