#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

void solve(int index, int *sol){
    if (index == 8 ){
        long long n = 9LL * 100LL +
                      8LL * 10000LL +
                      7LL * 1000000LL +
                      6LL * 100000000LL +
                      5LL * 10000000000LL +
                      4LL * 1000000000000LL +
                      3LL * 100000000000000LL +
                      2LL * 10000000000000000LL +
                      1LL * 1000000000000000000LL;

        n += sol[0] * 100000000000000000LL +
             sol[1] * 1000000000000000LL +
             sol[2] * 10000000000000LL +
             sol[3] * 100000000000LL +
             sol[4] * 1000000000LL +
             sol[5] * 10000000LL +
             sol[6] * 100000LL +
             sol[7] * 1000LL;

        long long m = (long long)sqrt(1.0 * n);

        if ( m * m  == n ){
            printf ("%lld\n", m);
            return ;
        }
        return ;
    }

    for (int i=0;i<=9;++i){
        sol[index] = i;
        solve(index + 1, sol);
    }
    return ;
}

int main(void){


    int sol[11];
    solve(0, sol);


    return 0;
}
