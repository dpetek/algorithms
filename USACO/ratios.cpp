/*
ID: dpetek11
LANG: C++
TASK: ratios
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

class Mixture{
    public:
        int a, b,c;
        Mixture(){}
        Mixture(int aa, int bb, int cc) : a(aa), b(bb),c(cc){}
};
Mixture m1, m2, m3,m;

int checkRatio(const Mixture &mix){
    int b1 = (m.a == 0) ? (mix.a == 0) : (mix.a % m.a==0);
    int b2 = (m.b == 0) ? (mix.b == 0) : (mix.b % m.b==0);
    int b3 = (m.c == 0) ? (mix.c == 0) : (mix.c % m.c==0);

    if (!b1 || !b2 || !b3) return -1;

    int r = -1;
    if ( m.a != 0) r = mix.a/m.a;
    if ( m.b != 0){
        if ( r < 0 ) r = mix.b/m.b;
        else{
            if ( mix.b / m.b != r ) return -1;
        }
    }

    if ( m.c != 0){
        if ( r < 0 ) r = mix.c/m.c;
        else{
            if ( mix.c / m.c != r ) return -1;
        }
    }

    if ( r < 0 ) return 0;
    return r;
}

int main(void){
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
    int a, b, c;


    scanf("%d %d %d", &a, &b, &c);
    m = Mixture(a,b,c);

    scanf("%d %d %d", &a, &b, &c);
    m1 = Mixture(a,b,c);

    scanf("%d %d %d", &a, &b, &c);
    m2 = Mixture(a,b,c);

    scanf("%d %d %d", &a, &b, &c);
    m3 = Mixture(a,b,c);


    Mixture miny(1000,1000,1000);
    int goal = -1;
    for (int k1=0;k1<100;++k1){
        for (int k2=0;k2<100;++k2){
            for (int k3=0;k3<100;++k3){
                if ( k1 + k2 + k3 == 0 )continue;
                Mixture mx(m1.a * k1 + m2.a * k2 + m3.a * k3,
                           m1.b * k1 + m2.b * k2 + m3.b * k3,
                           m1.c * k1 + m2.c * k2 + m3.c * k3);

                int res = checkRatio(mx);
                if ( res >= 0){
                    if ( k1 + k2 + k3 < miny.a + miny.b + miny.c) {
                        miny = Mixture(k1,k2,k3);
                        goal = res;
                    }
                }

            }
        }
    }
    if ( goal == -1 ) printf ("NONE\n");
    else printf ("%d %d %d %d\n", miny.a, miny.b, miny.c, goal);
    return 0;
}
