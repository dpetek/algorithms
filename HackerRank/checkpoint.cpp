#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define MOD 4207849484LL

#define MAX_VALUE 10000001

using namespace std;


int choose[5000005][50];

int Choose(int n, int k){
    if (k == 0 ) return 1;
    if (k == 1 ) return n;
    if ( k == 2){

        if ( MAX_VALUE / n < n / 2) return -1;

        if ( n % 2 == 0) return (n/2)*(n+1);
        return ((n+1)/2)*n;
    }

    if ( k == 3){
        if ( MAX_VALUE / n < n / 3) return -1;
        int t1 = n;
        int t2 = n+1;
        int t3 = n + 2;
        if ( t1 % 2 == 0) t1/=2;
        if ( t2 % 2 == 0) t2/=2;

        if ( t1 % 3 == 0) t1/=3;
        if ( t2 % 3 == 0) t2/=3;
        if ( t3 % 3 == 0) t3/=3;

        return t1 * t2 * t3;
    }
    if ( n == k ) return 1;
    if ( n - k == 1) return n;
    return choose[n][k];
}

int findMin(int n){
    fflush(stdout);
    int miny = 9999999;
    for (int i=1;i<=n;++i){
        for (int j=1;j<50;++j){

            int tmp = Choose(i,j);
            if ( tmp < 0 ) break;
            if ( tmp == n) miny = min(miny, i);
            if ( tmp > n) break;
        }
    }
    fflush(stdout);
    return miny;
}

int main(void){
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt","w", stdout);

    int test;
    int s;
    scanf("%d", &test);

    for (int i=1;i<5000002;++i){
        for (int j=0;j<50;++j){
            if ( j == 0 ) {choose[i][j] = 1;continue;}
            if ( j == 0 || i == 1) {choose[i][j] = 1;continue;}
            if ( i == 2 && j == 1) {choose[i][j] = 2;continue;}
            if ( i == 2 && j == 2) {choose[i][j] = 1;continue;}
            if ( i == j){choose[i][j] = 1; continue;}
            choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
        }
    }

    for (int iter=1;iter<=test;++iter){
        scanf ("%d", &s);
        int n = 1 + sqrt(s+1);
        int miny = 9999999;
        for (int a=1;a<=n;++a){
                if ( s % a != 0 ) continue;
                fflush(stdout);
                int t1 = findMin(a);
                int t2 = findMin(s/a);
                miny = min(miny, t1+t2);
        }

        printf ("Case #%d: %d\n", iter, miny);
    }

    return 0;
}
