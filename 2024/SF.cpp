#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int N;
struct Data
{
    int cnt;
    string s;
    bool operator < (const Data &o) const{
        if(cnt == o.cnt){
            string rs = s;
            reverse(rs.begin(), rs.end());
            string ro = o.s;
            reverse(ro.begin(), ro.end());
            return rs < ro;
        }
        return cnt < o.cnt;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    vector<Data> arr;
    for(int i=0; i<(1<<N); i++){
        bitset<10> b = i;
        int cnt = b.count();
        arr.push_back({cnt, b.to_string()});
    }
    sort(arr.begin(), arr.end());

    string s; cin >>s;
    while(s.length() < 10) s.insert(0, "0");
    for(int i=0; i<arr.size(); i++){
        if(s == arr[i].s){
            cout << i << '\n';
            break;
        }
    }

    return 0;
}