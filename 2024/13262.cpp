#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
long long A[5010], Dp[5010][5010], C[5010][5010], comp[5010][5010];
long long Q[5010], candidates[5010], front, rear, numOfInterval[5010];
/*
long long cross(long long x, long long i, long long j)
{
    long long l = j + 1, r = N + 1;
	while (l < r) {
		long long m = l + r >> 1;
		if (Dp[x-1][i] + C[i+1][m] <= Dp[x-1][j] + C[j+1][m]) l = m + 1;
		else r = m;
	}
	return l - 1;
}

void monotonQueueOpt(int x)
{
    candidates[0] = -1, Q[0] = 0, front = 0, rear = 1;
	for (int i=1; i<=N; i++){
		while(candidates[front] >= i) front++;
		Dp[x][i] = Dp[x-1][Q[front]] + C[Q[front]+1][i];
		numOfInterval[i] = numOfInterval[Q[front]] + 1;
		while(front + 1 < rear && candidates[rear-2] >= cross(x, Q[rear-1], i)) rear--;
		candidates[rear-1] = cross(x, Q[rear-1], i);
        Q[rear] = i;
        candidates[rear++] = -1;
	}
}
*/
void solve(int t, int s, int e, int optl, int optr)
{
    if(s > e) return;
    int mid = s + e >> 1;
    int opt = mid;
    comp[t][mid] = -1;
    for(int i=optl; i<=min(optr, mid-1); i++){
        long long val = comp[t-1][i] + C[i+1][mid];
        if(comp[t][mid] < val){
            comp[t][mid] = val;
            opt = i;
        }
    }

    solve(t, s, mid - 1, optl, opt);
    solve(t, mid + 1, e, opt, optr);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++){
        C[i][i] = A[i];
        for(int j=i+1; j<=N; j++){
            C[i][j] = C[i][j-1] | A[j];
        }
    }

    for(int i=1; i<=N; i++){
        //Dp[0][i] = C[1][i];
        comp[0][i] = C[1][i];
    }
    /*
    for(int i=1; i<K; i++){
        monotonQueueOpt(i);
    }
    */
    for(int i=1; i<K; i++){
        solve(i, 1, N, 1, N);
    }
    cout<<comp[K-1][N]<<'\n';

    //cout << Dp[K-1][N] << '\n';

    return 0;
}