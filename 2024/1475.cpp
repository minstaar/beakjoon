#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string str; cin >> str;
    int cnt[10] = {0};
    for(int i=0; i<str.length(); i++){
        int num = str[i] - '0';
        if(num == 6 || num == 9){
            if(cnt[6] <= cnt[9]) cnt[6]++;
            else cnt[9]++;
        }
        else cnt[num]++;
    }

    cout << *max_element(cnt, cnt + 10) << '\n';

    return 0;
}