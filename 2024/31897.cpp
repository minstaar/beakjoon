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
    
    cout << "1 2 3" << endl;
    cin >> res;
    query.push_back({1, 2, 3, res});

    for(int i=0; i<5; i++){ //consider ith query is false
        int x = -1, y = -1, z = -1;
        for(int j=0; j<3; j++){
            if(i == j) continue;
            auto [a, b, c, res] = query[j];
            if(a == 1) x = res;
            if(b == 1) y = res;
            if(c == 1) z = res;
        }
        if(i == 0){
            x = get<3>(query[3]) - y - z;
            if(x + 2 * y + 3 * z == get<3>(query[4])){
                cout << x << ' ' << y << ' ' << z << endl;
                break;
            }
        }
        if(i == 1){
            y = get<3>(query[3]) - x - z;
            if(x + 2 * y + 3 * z == get<3>(query[4])){
                cout << x << ' ' << y << ' ' << z << endl;
                break;
            }
        }
        if(i == 2){
            z = get<3>(query[3]) - x - y;
            if(x + 2 * y + 3 * z == get<3>(query[4])){
                cout << x << ' ' << y << ' ' << z << endl;
                break;
            }
        }
        if(i == 3 && x + 2 * y + 3 * z == get<3>(query[4])){
            cout << x << ' ' << y << ' ' << z << endl;
            break;
        }
        if(i == 4 && x + y + z == get<3>(query[3])){
            cout << x << ' ' << y << ' ' << z << endl;
            break;
        }
    }

    return 0;
}