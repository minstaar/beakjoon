#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 500010;
string str;
int N, d, sa[MAX], pos[MAX], lcp[MAX];

bool cmp(int i, int j)
{
    if(pos[i] != pos[j]) return pos[i] < pos[j];
    i += d, j += d;
    return (i < N && j < N) ? (pos[i] < pos[j]) : (i > j);
}

void constructSA()
{
    N = str.length();
    for(int i=0; i<N; i++){
        sa[i] = i;
        pos[i] = str[i];
    }
    for(d=1; ; d*=2){
        sort(sa, sa + N, cmp);
        int tmp[MAX] = {};
        for(int i=0; i<N-1; i++){
            tmp[i+1] = tmp[i] + cmp(sa[i], sa[i+1]);
        }
        for(int i=0; i<N; i++){
            pos[sa[i]] = tmp[i];
        }
        if(tmp[N-1] == N - 1) break;
    }
}

void constructLCP()
{
    for(int i=0, k=0; i<N; i++, k=max(k-1, 0)){
        if(pos[i] == 0) continue;
        for(int j=sa[pos[i]-1]; str[i+k]==str[j+k]; k++);
        lcp[pos[i]] = k;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> str;
    constructSA();
    constructLCP();
    for(int i=0; i<N; i++) cout << sa[i] + 1 << ' ';
    cout << '\n';
    for(int i=0; i<N; i++){
        if(i == 0) cout << "x ";
        else cout << lcp[i] << ' ';
    }

    return 0;
}