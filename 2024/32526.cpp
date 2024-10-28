#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N, K; cin >> N >> K;
    
    if(K == N - 1){ // N = 9, K = 1: aaaaaaaaa
        cout << "Yes\n";
        for(int i=0; i<N; i++) cout << 'a';
    }
    else if(K == 0){
        if(N == 2) cout << "No\n";
        else{ // N = 9, K = 0: abcdefghi
            cout << "Yes\n";
            char a = 'a';
            for(int i=0; i<N; i++){
                cout << a;
                a = (a == 'z' ? 'a' : a + 1);
            }
        }
    }
    else if(N % K == 0){ // N = 9, K = 3: aabaabaab
        cout << "Yes\n";
        string str = "";
        int M = N / K;
        for(int i=0; i<M/2; i++) str.push_back('a');
        for(int i=M/2; i<M; i++) str.push_back('b');
        for(int i=0; i<K; i++) cout << str;
    }
    else if(N % (K + 1) == 0){ // N = 9, K = 2: abaabaaba
        int M = N / (K + 1);
        if(M == 2) cout << "No\n";
        else{
            cout << "Yes\n";
            string str = "";
            for(int i=0; i<(M-1)/2; i++) str.push_back('a');
            if(M % 2 == 0) str.append("bb");
            else str.push_back('b');
            for(int i=str.size(); i<M; i++) str.push_back('a');
            for(int i=0; i<K+1; i++) cout << str;
        }
    }
    else cout << "No\n";

    return 0;
}