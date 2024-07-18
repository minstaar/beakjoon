#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    int M; cin >> M;
    vector<int> B(M);
    for(int i=0; i<M; i++) cin >> B[i];

    vector<int> res, common;
    int idxA = 0, idxB = 0;
    int val = 0;
    while(1){
        int tA, tB;
        val = 0;
        for(int i=idxA; i<A.size(); i++){
            for(int j=idxB; j<B.size(); j++){
                if(A[i] == B[j] && val < A[i]){
                    val = A[i];
                    tA = i, tB = j;
                    break;
                }
            }
        }
        if(val == 0) break;
        res.push_back(val);
        idxA = tA + 1, idxB = tB + 1;
    }
    cout << res.size() << '\n';
    for(auto x: res) cout << x << ' ';

    return 0;
}
