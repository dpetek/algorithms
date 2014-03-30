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

	int n;
	cin >> n ;
    long long f = 1LL;
	for (int i=1;i<=n;++i){
        f*=(long long)i;
        while(f%10LL==0LL) f/=10LL;


        f = f % 1000000000LL;

	}
    printf ("%lld\n", f%10LL);
	return 0;
}
