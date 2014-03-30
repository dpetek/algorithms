#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define pb push_back
#define fs first
#define sc second
using namespace std;

int gcd(int a, int b){
    if ( !b ) return a;
    return gcd(b, a%b);
}
vector <int> rev;

int main(void){
    int r, g;

    scanf ("%d %d", &r, &g);

    int n = gcd ( r, g );

    for (int i=1;i*i<=n;++i){
        if ( n % i == 0){
            printf ("%d %d %d\n", i, r / i, g / i);
            if ( i != n / i )
                rev.pb(n / i);
        }
    }
    if ( rev.size()){
        for (int i=rev.size()-1;i>=0;--i){
            printf ("%d %d %d\n", rev[i], r/rev[i], g/rev[i]);
        }
    }


    return 0;
}
