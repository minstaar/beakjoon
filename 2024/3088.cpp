#include <iostream>
using namespace std;

bool check[1000010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int cnt = 0;
    for(int i=0; i<N; i++){
        int a[3]; cin >> a[0] >> a[1] >> a[2];
        bool flag = false;
        for(int j=0; j<3; j++) flag |= check[a[j]];
        if(!flag) cnt++;
        check[a[0]] = check[a[1]] = check[a[2]] = true;
    }
    cout << cnt << '\n';

    return 0;
}