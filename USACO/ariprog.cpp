/*
ID: dpetek11
LANG: C++
TASK: ariprog
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

int n , m;
vector<bool> sq;
vector<pair<int, int> > res;

inline bool sqOk(int a){
    if ( a > m * m + m * m ) return false;
    return sq[a];
}

int main(void){
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);

    scanf ("%d %d", &n, &m);

    sq.resize(m*m + m*m , false);

    for (int i=0;i<=m;++i){
        for (int j=0;j<=m;++j){
//            if ( !sq[i*i + j*j] )printf ("%d\n", i*i + j*j);
            sq[i*i + j*j] = true;

        }
    }
    int limit = m * m + m * m;

    for (int a=0;a<=limit;++a){
        for (int b=1;a+(n-1)*b<=limit;++b){
            if ( sqOk(a) && sqOk(a+(n-1)*b)){

                bool ok = true;
                for (int i=1;i<n;++i){
                    if ( !sqOk(a+i*b) ){
                        ok = false;
                        break;
                    }
                }
                if ( ok) res.pb(make_pair(b, a));
            }
        }
    }
    sort(res.begin(), res.end());
    if ( res.size() ){
        for (int i=0;i<res.size();++i){
            printf ("%d %d\n", res[i].sc, res[i].fs);
        }
    }else{
        printf ("NONE\n");
    }

    return 0;
}
