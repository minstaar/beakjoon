#include <iostream>
using namespace std;
using ll = long long;

ll N, U, D;
ll A[300010], B[300010], func[300010];
ll diff[300010], cnt[300010]; //f(i-1)에서 f(i)로 넘어갈 때 1 <= j < i 인 Aj대신 Bj를 선택해야 하는 개수, 총 변화량


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> U >> D;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) cin >> B[i];

    ll delta = 0;
    for(int i=1; i<=N; i++){
        func[i] = func[i-1] + delta;
        
        if(A[i] < B[i]){ //Ai가 Bi보다 작은 경우 언제까지 Ai를 선택해야 하는지 기록
            func[i] += A[i];
            ll k = (B[i] - A[i]) / (U + D);
            if(i + k + 1 <= N){
                diff[i+k+1] += B[i] - A[i] - (k + 1) * (U + D);
                cnt[i+k+1]++;
            }
            delta += U;
        }
        else{
            func[i] += B[i];
            delta -= D;
        }
        
        if(cnt[i]){ //f(i)부터 Aj 대신 Bj를 선택
            func[i] += diff[i];
            delta -= (U + D) * cnt[i];
        }
    }

    for(int i=1; i<=N; i++) cout << func[i] << '\n';

    return 0;
}