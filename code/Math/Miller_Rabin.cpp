#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull pw(ull a, ull n, ull m)
{
    ull ret = 1;
    while(n){
        if(n & 1) ret = ret * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return ret;
}

bool miller_rabin(ull n, ull a)
{
    ull d = n - 1;
    while(d % 2 == 0){
        if(pw(a, d, n) == n - 1) return true;
        d >>= 1;
    }
    ull tmp = pw(a, d, n);
    return tmp == n - 1 || tmp == 1;
}

bool isPrime(ull n)
{
    vector<ull> alist = {2, 7, 61};
    
    if(n <= 1) return false;
    if(n <= 10000ULL){
        for(ull i=2; i*i<=n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    for(ull a: alist){
        if(!miller_rabin(n, a)) return false;
    }
    return true;
}