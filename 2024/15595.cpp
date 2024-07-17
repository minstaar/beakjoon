#include <iostream>
#include <map>
#include <string>
using namespace std;

int N;
map<string, int> submit, accepted;
int total, sum;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    while(N--){
        string name;
        int num, res, mem, time, lang, len;
        cin >> num >> name >> res >> mem >> time >> lang >> len;
        if(name == "megalusion") continue;
        if(res == 4 && accepted[name] == 0){
            total++;
            accepted[name] = 1;
            sum += submit[name];
        }
        if(res != 4 && accepted[name] == 0){
            submit[name]++;
        }
    }
    if(total == 0) cout << 0 << '\n';
    else{
        cout << fixed;
        cout.precision(9);
        cout << (double) total / (double)(sum + total) * 100 << '\n';
    }

    return 0;
}