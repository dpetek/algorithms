#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#define pb push_back
#define fs first
#define sc second

using namespace std;


vector<int> primes;
vector <int> sv;
void sieve(int size) {
        sv.resize(size, 0);

       for (int i=2; i*i <= size; i++) {
               if (!sv[i]) {
                       for(int j = i+i; j < size; j+=i) { sv[j] = 1; }
               }
       }
       for (int i=2; i<size; i++) {
               if (!sv[i]) { primes.pb(i);}
       }
}

int main(void){
    int test;
    scanf ("%d", &test);
    sieve(100000);

    for (int _test=0;_test<test;++_test){
        int n;
        long long l, h, tmp;

        scanf ("%d %lld %lld", &n, &l, &h);
        vector <long long> nums;
        set<long long> facts;

        for (int i=0;i<n;++i){
            scanf ("%lld", &tmp);
            nums.pb(tmp);

            int j = 0;
            while ( tmp > 1LL ){
                if ( tmp % primes[j] == 0LL ){
                    tmp/=primes[j];
                    facts.insert(primes[j]);
                }else ++j;
            }
        }
        printf ("Size %d\n", facts.size());

    }

    return 0;
}
