/*
ID: dpetek11
LANG: C++
TASK: milk
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

vector<pair<int, int> > v;

int main(void){
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int n, m, a, b, sum = 0;

    cin >> m >> n;

    for (int i=0;i<n;++i){
        cin >> a >> b;
        v.pb(make_pair(a, b));
    }

    sort(v.begin(), v.end());

    for (int i=0;i<v.size();++i){
        if ( v[i].sc > m ){
            sum+=m * v[i].fs;
            break;
        }else{
            m-=v[i].sc;
            sum+=v[i].fs*v[i].sc;
        }
    }

    printf ("%d\n", sum);

    return 0;
}
