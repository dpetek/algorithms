#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>

#define pb push_back
#define fs first
#define sc second

using namespace std;

bool isSqFree(long long n){

    for (long long i=2LL;i*i<=n;++i){
        if ( n % (i * i) == 0LL ) return false;
    }
    return true;
}

long long numNonSqFreeSmaller(long long n){
    long long res = 0LL;
    for (long long i=2LL;i*i<=n;++i){
        res += n / (i*i);
    }
    return res;
}

long long numPosition(long long n){
    return n - numNonSqFreeSmaller(n) + 1LL;
}


int main ( void ){
    long long n, low, high, middle;

    for(long long i=1LL;i<20LL;++i){
        printf ("%lld %lld\n", i, numPosition(i));
    }

    scanf ("%lld", &n);



    low = 1LL;
    high = n * 10;

    while ( low < high ){
        middle = (low + high)/2LL;
        long long np = numPosition(middle);
        if ( np == n )break;

        if ( numPosition(middle) <= n ) low = middle + 1;
        else high = middle;

    }

    printf ("%d\n", middle);
    return 0;
}
