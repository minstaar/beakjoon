#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> house, chicken;
vector<bool> visited

void find(int close)
{

}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int t; cin>>t;
            if(t == 1){
                house.push_back({i, j});
            }
            else if(t == 2){
                chicken.push_back({i, j});
                visited.push_back(false);
            }
        }
    }

    find(0);

    return 0;
}
