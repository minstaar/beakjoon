#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    
    ll sumA = 0, sumB = 0;
    vector<int> A(N), B(N);
    for(int i=0; i<N; i++){cin >> A[i]; sumA += A[i];}
    for(int i=0; i<N; i++){cin >> B[i]; sumB += B[i];}
    
    int topA = N - 1, topB = N - 1;
    while(K-- && (sumA > 0 || sumB > 0)){
        if(sumA > sumB){
            sumA -= A[topA];
            topA--;
        }
        else{
            sumB -= B[topB];
            topB--;
        }
    }
    cout << max(sumA, sumB) << '\n';

    return 0;
}