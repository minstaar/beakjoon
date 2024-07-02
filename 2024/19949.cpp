#include <iostream>
using namespace std;
using ll = long long;

int ans[10], arr[10], cnt;

void dfs(int num, int correct)
{
    if(num == 10){
        if(correct >= 5) cnt++;
        return;
    }
    for(int i=1; i<=5; i++){
        if(num >= 2 && arr[num-2] == arr[num-1] && arr[num-1] == i) continue;
        arr[num] = i;
        dfs(num + 1, correct + (ans[num] == i));
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(int i=0; i<10; i++) cin >> ans[i];
    dfs(0, 0);
    cout << cnt << '\n';

    return 0;
}