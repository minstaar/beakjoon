#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    multiset<int> book;
    int Q; cin >> Q;
    while(Q--){
        int a; cin >> a;
        if(a == 3){
            if(book.empty()){
                cout << 0 << '\n';
                continue;
            }
            int page = 1;
            auto it = book.begin();
            while(1){
                it = book.lower_bound((*it) * 2);
                if(it == book.end()) break;
                page++;
            }
            cout << page << '\n';

        }
        else{
            int b; cin >> b;
            if(a == 1) book.insert(b);
            if(a == 2){
                auto it = book.find(b);
                if(it != book.end()) book.erase(it);
            }
        }
    }

    return 0;
}