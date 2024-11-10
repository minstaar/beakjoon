#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    string s; cin >> s;
    vector<pair<char, int>> arr(N);
    for(int i=0; i<N; i++){
        arr[i] = {s[i], i};
    }
    sort(arr.begin(), arr.end());
    vector<bool> chk(N);
    for(int i=M; i<N; i++) chk[arr[i].second] = true;
    for(int i=0; i<N; i++){
        if(chk[i]) cout << s[i];
    }

    return 0;
}