#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

vector<int> manacher(string &s)
{
    int N = s.size(), k = -1, r = -1;
    vector<int> p(N);
    for(int i=0; i<N; i++){
        if(i <= r) p[i] = min(r - i, p[2*k-i]);
        while(i - p[i] - 1 >= 0 && i + p[i] + 1 < N && s[i-p[i]-1] == s[i+p[i]+1]) p[i]++;
        if(i + p[i] > r){
            k = i, r = i + p[i];
        }
    }
    return p;
}

int arr[510][510];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<string> str(N);
    for(int i=0; i<N; i++){
        string t; cin >> t;
        string s = "$";
        for(int i=0; i<t.size(); i++){
            s += t[i];
            s += '$';
        }
        str[i] = s;
    }

    ll res = 0;
    for(int i=0; i<N; i++){
        auto p = manacher(str[i]);
        for(int j=0; j<M*2+1; j++){
            if(j % 2 == 0){
                arr[i][j/2] = p[j] / 2;
                res += arr[i][j/2];
            }
        }
    }

    for(int i=0; i<N-1; i++){
        for(int j=0; j<M; j++){
            int t = arr[i][j];
            for(int k=i+1; k<N; k++){
                t = min(t, arr[k][j]);
                if(t == 0) break;
                res += t;
            }
        }
    }
    cout << res << '\n';

    return 0;
}