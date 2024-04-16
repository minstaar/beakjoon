#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
long long A[5010], Dp[5010][5010], C[5010][5010];
long long Q[5010], candidates[5010], front, rear, numOfInterval[5010];

long long cross(long long x, long long i, long long j)
{
    long long l = j + 1, r = N + 1;
	while (l < r) {
		long long m = l + r >> 1;
		if (Dp[x - 1][i - 1] + C[i][m] <= Dp[x - 1][j - 1] + C[j][m])l = m + 1;
		else r = m;
	}
	return l - 1;
}

void monotonQueueOpt(int x)
{
    candidates[0] = N, Q[0] = 0, front = 0, rear = 1;
	for (int i=1; i<=N; i++) {
		while(candidates[front] >= i) front++;
		Dp[x][i] = Dp[x-1][i] + C[Q[front]][i];
		numOfInterval[i] = numOfInterval[Q[front]] + 1;
		while(front + 1 < rear && cross(x, Q[rear - 1], i) >= candidates[rear - 2]) rear--;
		candidates[rear - 1] = cross(x, Q[rear - 1], i); Q[rear] = i; candidates[rear++] = N;
	}
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
        Dp[1][i] = C[1][i] + C[i+1][N];
    }
    for(int i=2; i<=K; i++){
        monotonQueueOpt(i);
    }

    cout << Dp[K][N] << '\n';

    return 0;
}