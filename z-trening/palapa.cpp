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

const int MOD = 9973;
int nprimes, neven;

int myPow(int a, int b){
    if ( b<=0 ) return 1;
    if ( b == 1 ) return a%MOD;
    int tmp = myPow(a, b/2)%MOD;

    if ( b&1) return (((a*tmp)%MOD)*tmp)%MOD;
    return (tmp*tmp)%MOD;
}

bool isPrime(int &n){
    if (n == 2 ) return true;
    if ( !(n&1)) return false;

    for (int i=3;i*i<=n;i+=2){
        if ( n % i == 0 ) return false;
    }
    return true;
}


int calc(int n){
    return (neven * myPow(10, n-2))%MOD +
           (((9 * nprimes)%MOD) * myPow(10,n-3))%MOD-
           (((neven * nprimes)%MOD)*myPow(10, n-4))%MOD;
}



int main(void){
    int _test, n;

    scanf("%d", &_test);

    nprimes = neven = 0;


    for (int i=2;i<100;++i){
        if ( isPrime(i)) {++nprimes;}
        if ( i >= 10){
            if ( ((i/10) + (i%10))%2==0){++neven;}
        }
    }
    for (int test=0;test<_test;++test){
        scanf("%d", &n);
        printf ("%d\n", (((calc(n)%MOD)+MOD)%MOD));
    }

    return 0;
}
