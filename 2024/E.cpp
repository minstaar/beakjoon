#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    string str; cin >> str;
    for(int i=0; i<N; i++){
        if('9' - str[i] + 1 <= M){
            M -= '9' - str[i] + 1;
            str[i] = '0';
        }
    }
    str[str.length() - 1] += M % 10;
    cout << str << '\n';

    return 0;
}