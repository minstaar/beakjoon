#include <iostream>
#include <algorithm>
using namespace std;

int N, A, B;
int arr[110], ans;

void solve(int cur, int time, int cnt, int spand = A)
{
    if(time > arr[N-1] || cur > N){
        ans = max(ans, cnt);
        return;
    }
    if(time + spand <= arr[cur]) solve(cur + 1, time + spand, cnt + 1, spand);
    else solve(cur + 1, time, cnt, spand);
    if(spand == A){
        int next = cur;
        for(int i=1; i<A; i++){
            if(time + B * i >= arr[next]) next++;
            if(next > N) break;
            solve(next, time + B * i, cnt, spand - i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> A >> B;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);
    solve(0, 0, 0);
    cout << ans << '\n';

    return 0;
}