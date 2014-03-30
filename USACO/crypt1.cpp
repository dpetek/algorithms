/*
ID: dpetek11
LANG: C++
TASK: crypt1
*/
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

bool allowed[10];

inline int my_pow(int a, int b){
    int r = 1;
    for (int i=0;i<b;++i) r*=a;
    return r;
}

bool ok(int n, int d){
    int p = my_pow(10,d-1);

    if ( n < p || n >= p*10) return false;

    while (n){
        if ( !allowed[n%10] ) return false;
        n/=10;
    }

    return true;
}

int main(void){
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);

    int n, tmp;

    scanf ("%d", &n);

    for (int i=0;i<n;++i){
        scanf("%d", &tmp);
        allowed[tmp] = true;
    }
    int cnt = 0;
    for (int n1 = 100;n1<1000;++n1){
        for (int n2=10;n2<100;++n2){
            if ( !ok(n1,3) || !ok(n2,2)) continue;
            int s1 = n1 * (n2 % 10);
            if ( !ok(s1,3)) continue;
            int s2 = n1 * (n2/10);
            if ( !ok(s2,3))continue;
            int s = s1 + s2*10;
            if ( !ok(s, 4)) continue;
            ++cnt;
        }
    }

    printf ("%d\n", cnt);
    return 0;
}
