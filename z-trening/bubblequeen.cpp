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

int cnt1[2000003];
int cnt2[2000003];

int main(void){
    int n;
    scanf("%d", &n);
    double avg = 0.0, nd = 1.0*n*n;

    avg = 2.0 * n - 1.0;


    for (int i=1;i<=n;++i){
        if ( i != n)
            avg+= (4.0 * i * (i-1)) / nd;
        else
            avg+= (2.0 * i * (i-1)) / nd;
    }

    printf ("%.3lf\n", avg-1.0);

    return 0;
}
