#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll psum[1000010], cnt[1000010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(int i=2; i<=1000000; i++){
        psum[i] += psum[i-1] + i;
    }
    for(int i=2; i<=1000000; i++){
        for(int j=i-1; j>=1; j--){
            if(psum[i] - psum[j] > 1000000) break;
            cnt[psum[i]-psum[j]]++;
        }
    }
    int k;
    while((cin >> k) && k != 0){
        cout << cnt[k] << '\n';
    }

    return 0;
}