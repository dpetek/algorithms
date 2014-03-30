
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cmath>
#define pb push_back
#define fs first
#define sc second
#define foreach(c,it) for(typeof(((c).begin())) it=((c).begin());(it)!=((c).end());++(it))
#define _sz(c) ((int)c.size())
#define cstr(s) ((s).c_str())
using namespace std;

vector<int> primes;
bool sieve[500004]={0};

void doSieve(int n){

    for (int i=2;i<=n;++i){
        if ( !sieve[i] ){
            primes.pb(i);
            for (int j=i+i;j<n;j+=i) sieve[j]=true;
        }
    }

}

int sum[500005];

void precalc(){
    int cnt = 0;

    for (int i=2;i<=500000;++i){
        int  j=0, cnt =1, num=i;
        double res;

        if ( !sieve[i] ){
            sum[i] = 1;
            continue;
        }
        while(num > 1){
            if ( num % primes[j] == 0){
                cnt*=primes[j];
                num/=primes[j];
            }else{
                if ( cnt ){
                    res *= cnt /  (primes[j]-1);
                    cnt =0;
                }
                ++j;
            }
        }
        if ( cnt ){
            res *= cnt / (primes[j]-1);
        }
        sum[i] = (int)+ 1 - i;
    }

}

int main(void){
    int __tests = 0;

    scanf("%d", &__tests);
    doSieve(500002);
    precalc();
    printf ("DONE1\n");fflush(stdout);
    int num;
    for (int test=1;test<=__tests;++test){
        scanf("%d", &num);
        printf("%d\n", sum[num]);
    }


    return 0;
}
