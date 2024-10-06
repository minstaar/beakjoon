#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        string s; cin >> s;
        stack<char> st;
        for(int i=0; i<N; i++){
            st.push(s[i]);
            if(st.top() == 'B' && st.size() >= 3){
                char top = st.top(); st.pop();
                char top1 = st.top(); st.pop();
                char top2 = st.top(); st.pop();
                if(top2 == 'A' && top1 == 'B' && top == 'B'){
                    int cnt = 1;
                    while(st.size() > 1 && st.top() == 'B'){
                        st.pop();
                        if(st.top() != 'A'){
                            st.push('B');
                            break;
                        }
                        st.pop();
                        cnt++;
                    }
                    st.push('B');
                    for(int i=1; i<=cnt; i++){
                        st.push('A');
                    }
                }
                else{
                    st.push(top2), st.push(top1), st.push(top);
                }
            }
        }

        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        for(int i=0; i<res.size(); i++) cout << res[i];
        cout << '\n';
    }

    return 0;
}