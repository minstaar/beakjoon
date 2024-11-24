#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N+1);

    auto query = [&](int a, int b, char op){
        cout << "? " << a << ' ' << op << ' ' << b << endl;
        char ret; cin >> ret;
        return ret;
    };

    for(int i=1; i<=N; i+=2){
        if(i == N){
            if(query(i - 1, i, '*') == '+'){
                if(arr[i-1] != 0) arr[i] = arr[i-1];
                else if(query(i - 1, i, '+') == '+'){
                    arr[i-1] = arr[i] = 1;
                    arr[i-2] = -1;
                }
                else{
                    arr[i-1] = arr[i] = -1;
                    arr[i-2] = 1;
                }
            }
            else{
                if(arr[i-1] != 0) arr[i] = -1 * arr[i-1];
                else if(query(i - 2, i, '+') == '+'){
                    arr[i-2] = arr[i] = 1;
                    arr[i-1] = -1;
                }
                else{
                    arr[i-2] = arr[i] = -1;
                    arr[i-1] = 1;
                }
            }
            break;
        }
        if(query(i, i + 1, '*') == '+'){ // arr[i]와 arr[i+1] 부호가 동일
            if(query(i, i + 1, '+') == '+') arr[i] = arr[i+1] = 1;
            else arr[i] = arr[i+1] = -1;

            if(i > 1 && arr[i-1] == 0){
                if(query(i - 1, i, '*') == '+'){
                    arr[i-1] = arr[i];
                    arr[i-2] = -1 * arr[i];
                }
                else{
                    arr[i-1] = -1 * arr[i];
                    arr[i-2] = arr[i];
                }
            }
        }
        else{ // arr[i]와 arr[i+1] 부호가 다름
            if(i > 1){
                if(query(i - 1, i, '*') == '+'){ // arr[i-1]과 arr[i] 부호가 같음
                    if(arr[i-1] != 0){
                        arr[i] = arr[i-1];
                        arr[i+1] = -1 * arr[i];
                    }
                    else if(query(i - 1, i, '+') == '+'){
                        arr[i-1] = arr[i] = 1;
                        arr[i-2] = arr[i+1] = -1;
                    }
                    else{
                        arr[i-1] = arr[i] = -1;
                        arr[i-2] = arr[i+1] = 1;
                    }
                }
                else{ // arr[i-1]과 arr[i] 부호가 다름
                    if(arr[i-1] != 0){
                        arr[i] = -1 * arr[i-1];
                        arr[i+1] = arr[i-1];
                    }
                    else if(query(i - 2, i, '+') == '+'){
                        arr[i-2] = arr[i] = 1;
                        arr[i-1] = arr[i+1] = -1;
                    }
                    else{
                        arr[i-2] = arr[i] = -1;
                        arr[i-1] = arr[i+1] = 1;
                    }
                }
            }
        }
    }

    cout << '!';
    for(int i=1; i<=N; i++) cout << (arr[i] == 1 ? " +" : " -");
    cout << endl;

    return 0;
}