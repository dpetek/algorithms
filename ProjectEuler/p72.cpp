#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;


vector<int> primes;
vector<char> isPrime;

void sieve(int n){
    isPrime = vector<char>(n, '.');

    for (int i=2;i*i<=n;++i){
        if ( isPrime[i] == '.'){
            for(int j=i+i;j<=n;j+=i){
                isPrime[j] = 'x';
            }
        }
    }
    for (int i=2;i<=n;++i){
        if ( isPrime[i] == '.') primes.push_back(i);
    }
}


int calcFi(int n){
    if ( isPrime[n] == '.' ) return n-1;
    int tmp = n, i = 0;
    double fi = (double)n;
    while ( tmp > 1){

        if ( tmp % primes[i] == 0 ){
            while(tmp % primes[i] == 0 && tmp > 1) tmp /= primes[i];
            fi*=(1.0 - 1.0 / primes[i]);
        }

        ++i;
    }
    return (int)(fi);
}


int main(void){
    sieve(1000000);

    long long cnt = 0LL;

    for (int i=2;i<=1000000;++i){
        if ( i % 1000 == 0 ) printf ("%d\n", i );
        cnt+=(long long)calcFi(i);
    }
    printf ("%lld\n", cnt);
    return 0;
}
