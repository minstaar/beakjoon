#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int arr[10], func[10];
    for(int i=0; i<10; i++){
        cin >> arr[i];
        func[arr[i]] = i;
    }

    string A, B; cin >> A >> B;
    int a = 0, b = 0;
    for(int i=0; i<A.size(); i++){
        a *= 10;
        a += func[A[i] - '0'];
    }
    for(int i=0; i<B.size(); i++){
        b *= 10;
        b += func[B[i] - '0'];
    }

    int sum = a + b;
    vector<int> res;
    while(sum > 0){
        res.push_back(arr[sum%10]);
        sum /= 10;
    }
    reverse(res.begin(), res.end());
    for(auto i: res) cout << i;

    return 0;
}