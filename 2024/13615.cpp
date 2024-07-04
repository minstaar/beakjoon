#include <iostream>
#include <random>
using namespace std;
using ll = long long;

int N;

typedef vector<ll> vll;
vll operator * (vector<vll> &a, vll &b)
{
    vll ret(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ret[i] += a[i][j] * b[j];
        }
    }
    return ret;
}

bool operator == (vll &a, vll &b)
{
    for(int i=0; i<N; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> ran(0, 1);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int M; cin >> N >> M;
    vector<vll> arr(N, vll(M));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    vector<vll> A(N, vll(N)), B(N, vll(N)), C(N, vll(N));
    for(int st=0; st<=M-3*N; st++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                A[i][j] = arr[i][j+st];
                B[i][j] = arr[i][j+N+st];
                C[i][j] = arr[i][j+2*N+st];
            }
        }
        bool flag = true;
        for(int i=0; i<50; i++){
            vll r(N);
            for(int j=0; j<N; j++) r[j] = ran(mt);
            vll t = B * r;
            if(A * t != C * r){
                flag = false;
                break;
            }
        }
        if(flag){
            cnt += 3 * N * N;
            st += 3 * N - 1;
        }
    }
    cout << cnt << '\n';

    return 0;
}