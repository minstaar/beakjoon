#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 360000;

vector<int> constructZ(vector<int> &s)
{
    int N = s.size(), l = 0, r = 0;
    vector<int> z(N);
    z[0] = N;
    for(int i=1; i<N; i++){
        if(i <= r) z[i] = min(r - i + 1, z[i-l]);
        while(i + z[i] < N && s[z[i]] == s[i+z[i]]) z[i]++;
        if(i + z[i] - 1 > r){
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<bool> c1(MAX), c2(MAX);
    for(int i=0; i<N; i++){
        int a; cin >> a;
        c1[a] = true;
    }
    for(int i=0; i<N; i++){
        int a; cin >> a;
        c2[a] = true;
    }
    
    vector<int> str(MAX * 3 + 1);
    for(int i=0; i<MAX; i++){
        str[i] = c2[i];
        str[i+MAX+1] = c1[i];
        str[i+MAX*2+1] = c1[i];
    }
    str[MAX] = -1;

    auto z = constructZ(str);
    bool flag = false;
    for(int i=MAX+1; i<MAX*3+1; i++){
        if(z[i] == MAX){
            flag = true;
            break;
        }
    }
    cout << (flag ? "possible\n" : "impossible\n");

    return 0;
}