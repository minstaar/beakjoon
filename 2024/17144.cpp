#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int r, c, t; cin>>r>>c>>t;
    vector<vector<int>> arr(r, vector<int>(c));
    pair<int, int> air1, air2;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[i][j];
            if(arr[i][j] == -1){
                air1 == {0, 0} ? (air1 = {i, j}) : (air2 = {i, j});
            }
        }
    }
    
    return 0;
}
