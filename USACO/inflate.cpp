/*
ID: dpetek11
LANG: C++
TASK: inflate
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

int dp[10005] = {0};
vector<pair<int,int> > v;

int main(void){
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
    int m, n , a, b;

    scanf("%d %d",&m, &n);

    for (int i=0;i<n;++i){
        scanf("%d %d", &a, &b);
        v.pb(make_pair(a,b));
    }
    int maxy = 0;
    for(int i=0;i<v.size();++i){
        for (int j=v[i].sc;j<=m;++j){
            dp[j] = max(dp[j], dp[j-v[i].sc] + v[i].fs);
            maxy = max(maxy, dp[j]);
        }
    }
    printf ("%d\n", maxy);


    return 0;
}
