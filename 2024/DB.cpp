#include <iostream>
#include <bitset>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int arr[3]; cin >> arr[0] >> arr[1] >> arr[2];
    string str;
    for(int i=0; i<3; i++){
        string s;
        for(int j=0; j<4; j++){
            s.push_back('0' + (arr[i] & 1));
            arr[i] >>= 1;
        }
        reverse(s.begin(), s.end());
        str += s;
    }
    bitset<20> bit(str);
    int res = bit.to_ulong();
    for(int i=3; i>=0; i--){
        if(res < pow(10, i)) cout << 0;
        else{
            int m = res / pow(10, i);
            cout << m;
            res -= m * pow(10, i);
        }
    }

    return 0;
}