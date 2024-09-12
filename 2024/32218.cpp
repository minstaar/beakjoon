#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> a(210), b(210);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    int cnt = 1;
    while(a != b){
        for(int i=0; i<N; i++){
            int t = 0;
            for(int j=i+1; j<N; j++){
                if(a[i] < a[j]) t++;
            }
            b[i] = t;
        }
        a = b;
        b.assign(210, 0);
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}