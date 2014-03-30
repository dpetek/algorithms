/*
ID: dpetek11
LANG: C++
TASK: frac1
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

int used[262][262] = {0};

vector<pair<double,pair<int,int> > >sol;

int gcd(int a, int b){
    if ( !b ) return a;
    return gcd(b, a%b);
}

int main(void){
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);

    int n;
    scanf("%d", &n);
    sol.pb(make_pair(0.0, make_pair(0,1)));
    for (int i=1;i<=n;++i){
        for (int j=i;j<=n;++j){
            if ( !j) continue;

            int g = gcd(i,j);
            int a = i / g;
            int b = j / g;
            if ( used[a][b] ) continue;
            used[a][b] = true;
            sol.pb(make_pair(1.0*a/b, make_pair(a,b)));
        }
    }

    sort(sol.begin(), sol.end());
    for (int i=0;i<sol.size();++i) printf("%d/%d\n", sol[i].sc.fs, sol[i].sc.sc);

    return 0;
}
