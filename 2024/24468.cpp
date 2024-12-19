#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int L, N, T; cin >> L >> N >> T;
    vector<pair<int, char>> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    int cnt = 0;
    for(int i=0; i<T; i++){
        vector<bool> loc(L+1);
        for(int j=0; j<N; j++){
            if(arr[j].first == 1 && arr[j].second == 'L'){
                arr[j] = {0, 'R'};
            }
            else if(arr[j].first == L - 1 && arr[j].second == 'R'){
                arr[j] = {L, 'L'};
            }
            else if(arr[j].second == 'L') arr[j].first--;
            else arr[j].first++;
            
            if(loc[arr[j].first]) cnt++;
            loc[arr[j].first] = true;
        }
    }

    cout << cnt << '\n';

    return 0;
}