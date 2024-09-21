#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) arr[i] = i;

    int sum = 1e9;
    vector<int> res;
    do{
        int tmp = 0;
        for(int i=0; i<N-1; i++){
            tmp += (arr[i] ^ arr[i+1]);
        }

        for(auto x: arr) cout << x << ' ';
        cout << '\n';
        cout << tmp << ' ' << (arr[0] ^ arr[N-1]) << "\n\n";
    }while(next_permutation(arr.begin(), arr.end()));

    return 0;
}