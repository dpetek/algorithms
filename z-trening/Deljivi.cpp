#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define fs first
#define sc second

using namespace std;

long long calcFast(long long a, long long b, long long k){
    long long _a, _b;


    if ( a % k == 0LL ) _a = a/k;
    else _a = a/k + 1LL;

    _a*=k;

    _b = (b/k)*k;

    if ( _b < _a ) return 0LL;
    return (_b - _a) / k + 1LL;
}
long long calcSlow(long long a, long long b, long long k){

    long long cnt = 0LL;
    for (long long i=a;i<=b;++i){
        if ( i % k == 0 ) ++cnt;
    }
    return cnt;
}



int main(void){

    long long a, b, k;

    scanf("%lld %lld %lld", &a, &b, &k);

    printf ("%lld\n", calcFast(a, b, k));

    return 0;
}
