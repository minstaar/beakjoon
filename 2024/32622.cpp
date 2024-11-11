#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool arr[300010];
vector<int> flip;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    flip.push_back(1);
    int idx = 0;
    bool flag = arr[0];
    for(int i=1; i<N; i++){
        if(flag != arr[i]){
            flip.push_back(1);
            idx++;
            flag = arr[i];
        }
        else flip[idx]++;
    }

    if(flip.size() <= 2){
        cout << N << '\n';
        return 0;
    }
    int ans = 0;
    for(int i=1; i<flip.size()-1; i++){
        ans = max(ans, flip[i] + flip[i-1]);
        ans = max(ans, flip[i] + flip[i+1]);
    }
    cout << ans << '\n';
    
    return 0;
}