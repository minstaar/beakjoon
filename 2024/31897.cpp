#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<tuple<int, int, int, int>> query;
    
    int res;
    cout << "1 0 0" << endl;
    cin >> res;
    query.push_back({1, 0, 0, res});
    
    cout << "0 1 0" << endl;
    cin >> res;
    query.push_back({0, 1, 0, res});

    cout << "0 0 1" << endl;
    cin >> res;
    query.push_back({0, 0, 1, res});
    
    cout << "1 1 1" << endl;
    cin >> res;
    query.push_back({1, 1, 1, res});
    
    cout << "2 0 1" << endl;
    cin >> res;
    query.push_back({2, 0, 1, res});

    for(int i=0; i<5; i++){ //consider ith query is false
        bool valid = true;
        int x = -1, y = -1, z = -1;
        for(int j=0; j<5; j++){
            if(i == j) continue;
            auto [a, b, c, res] = query[j];
            
        }
    }
}