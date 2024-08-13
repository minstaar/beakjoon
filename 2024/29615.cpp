#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    int arr[1010], cnt = 0;
    set<int> s;
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=0; i<M; i++){
        int a; cin >> a;
        s.insert(a);
    }
    for(int i=0; i<M; i++){
        if(s.find(arr[i]) == s.end()) cnt++;
    }
    cout << cnt << '\n';

    return 0;
}