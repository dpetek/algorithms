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
    printf ("Ok\n");fflush(stdout);
        sv.resize(size, 1);
        printf ("Ok\n");fflush(stdout);

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
    //sieve(100000);
    printf ("sieve done\n");fflush(stdout);
    for (int _test=0;_test<test;++_test){
        int n, l, h, tmp;

        scanf ("%d %d %d", &n, &l, &h);
        vector <int> nums;
        set<int> facts;

        for (int i=0;i<n;++i){
            scanf ("%d", &tmp);
            nums.pb(tmp);
            int j = 0;
            while ( tmp > 1 ){
                if ( tmp % primes[j] == 0 ){
                    tmp/=primes[j];
                }else ++j;
            }
        }

    }

    return 0;
}
