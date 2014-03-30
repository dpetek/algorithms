#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define pb push_back
#define fs first
#define sc second
using namespace std;

int main(void){
    int n, m;

    scanf ("%d %d", &n, &m);

    vector <int> sieve(n + 5, 0 );
    int cnt = 0, res = -1;
    for (int i=2;i<=n;++i){
        if ( !sieve[i] ){
            for (int j=i;j<=n;j+=i){
                if ( !sieve[j] ) ++cnt;
                sieve[j] = 1;
                if ( cnt == m ) {res = j;break;}
            }
        }
        if ( res > 0 ) break;
    }

    printf ("%d\n", res);

    return 0;
}
