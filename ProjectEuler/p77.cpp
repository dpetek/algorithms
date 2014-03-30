#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> primes;
vector<char> isPrime;

int dp[1000000];



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

int main(void){

    sieve(100000);

    dp[0] = 1;


    for (int i=0;i<primes.size();++i){
        for(int j=0;j<=1000;++j){
            dp[j+primes[i]] += dp[j];
            if ( j == 7 ) printf ("[%d %d]+= dp[%d] == %d\n",j, primes[i] , j - primes[i], dp[j-primes[i]]);
        }
    }

    printf ("%d\n", dp[7]);
    return 0;
}
