#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>


using namespace std;


vector<int> primes;
vector<char> isPrime;



void sieve(int n){
    isPrime = vector<char>(n+1, '.');

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

bool checkPrime(int n){
    if ( n < isPrime.size()) return isPrime[n] == '.';

    for (int i=3;i*i<=n;i+=2){
        if ( n % i == 0 ) return false;
    }
    return true;
}

int cc1(int a, int b){
    int tmpb = b;
    while ( b ){
        a = a * 10;
        b/=10;
    }
    return a+tmpb;
}

int cc2(int a, int b){
    return cc1(b, a);
}
int miny= 99999999;
void solve(int index, int *sol){
    if ( index == 5 ){
        int sum = primes[sol[0]]+ primes[sol[1]]+ primes[sol[2]]+ primes[sol[3]] + primes[sol[4]];
        if (sum < miny){
            printf ("Found sol %d %d %d %d %d => %d\n", primes[sol[0]], primes[sol[1]], primes[sol[2]], primes[sol[3]], primes[sol[4]], sum);
            miny = sum;
        }
        return ;
    }

    if ( index == 0 ){
        int start = 1;
        for (int i=start;i<primes.size();++i){
            sol[index] = i;
            solve(index+1, sol);
        }
    }else{
        int start = sol[index-1];
        for (int i=start;i<primes.size();++i){
            bool ok = true;
            for (int j=0;j<index;++j){
                if ( !checkPrime(cc1(primes[sol[j]], primes[i])) || ! checkPrime(cc2(primes[sol[j]], primes[i]))){
                    ok = false;
                    break;
                }
            }
            if ( ok ){
                sol[index] = i;
                solve(index + 1, sol);
            }
        }
    }

    return ;
}


int main(void){
    sieve(10000);
    int sol[6];
    solve(0, sol);

    return 0;
}
