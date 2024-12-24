#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++){
        string str; cin >> str;
        reverse(str.begin(), str.end());
        cout << str << '\n';
    }

    return 0;
}