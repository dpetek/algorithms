#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#define pb push_back
#define fs first
#define sc second

using namespace std;
#define MOD 1000007LL

int primeFactorCount[1000005];
vector<int> primes;
vector<bool> isprime;

void sieve(int n){
    isprime = vector<bool>(n, 1);
    isprime[1] = 0;
    for (int i=2;i*i<n;++i){
        if (isprime[i]){
            for (int j=i+i;j<=n;j+=i){
                isprime[j] = 0;
            }
        }
    }
    primes.clear();
    for (int i=2;i<=n;++i){
        if (isprime[i] ) primes.push_back(i);
    }

}


void updateFactors(int n){
    int index = 0;

    while ( n > 1 ){
        if ( isprime[n] ){
            primeFactorCount[n] += 2;
            break;
        }
        if ( n % primes[index] == 0){
            primeFactorCount[primes[index]] += 2;
            n/=primes[index];
        }else ++index;
    }

}


int main(void){
    sieve(1000003);

    int n;
    scanf("%d", &n);

    for (int i=1;i<=n;++i){
        updateFactors(i);
    }

    long long res = 1LL;


    for (int i=2;i<=n;++i){
        res %= MOD;
        res = (res * (long long)(primeFactorCount[i] + 1))%MOD;
    }
    printf ("%lld\n", res % MOD);

	return 0;
}
