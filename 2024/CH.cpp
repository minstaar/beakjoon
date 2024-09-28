#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, A[200010], B[200010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> B[i];
    
    int diff1 = A[N-1] - B[N-1], diff2 = B[N-1] - A[N-1]; // diff1: A > B, diff2: A < B
    for(int i=0; i<N-1; i++){
        if(A[i] == B[i]) continue;
        if(A[i] > B[i]){
            if(i + 2 < N) diff1 += A[i] - B[i];
            else diff1 -= A[i] - B[i];
        }
        else{
            if(i + 1 < N) diff1 += B[i] - A[i];
            else diff1 -= B[i] - A[i];
        }
    }
    for(int i=0; i<N-1; i++){
        if(A[i] == B[i]) continue;
        if(A[i] > B[i]){
            if(i + 1 < N) diff2 += A[i] - B[i];
            else diff2 -= A[i] - B[i];
        }
        else{
            if(i + 2 < N) diff2 += B[i] - A[i];
            else diff2 -= B[i] - A[i];
        }
    }
    cout << max(diff1, diff2) << '\n';

    return 0;
}