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


int main(void){

	long long n;
	scanf("%lld", &n);

	if ( n < 10LL){
	    if ( n == 0LL)
            printf ("10\n");
	    else
            printf ("%lld\n", n);
        return 0;
	}

    vector<long long> factors;
    for (long long i=9LL;i>=2LL;--i){
        while(n % i == 0 ){
            factors.push_back(i);
            n/=i;
        }
    }

    if ( n > 1LL ){
        printf ("-1\n");
    }else{
        sort(factors.begin(), factors.end());
        for (int i=0;i<factors.size();++i) printf ("%lld", factors[i]);
        printf ("\n");
    }

	return 0;
}
