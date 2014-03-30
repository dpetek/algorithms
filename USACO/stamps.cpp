/*
ID: dpetek11
LANG: C++
TASK: stamps
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

int n, m, maxy = 0;
vector<int> values;
int dp[2000002];
const int INF = (1<<29);

int main(void){
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);

    scanf("%d %d", &m, &n);
    int tmp;
    for (int i=0;i<n;++i){
        scanf("%d",&tmp);
        maxy = max(maxy,tmp);
        values.pb(tmp);
    }
    dp[0] = 0;
    for (int i=1;i<=maxy*m+ 1;++i){
        dp[i] = INF;
        for (int j=0;j<values.size();++j){
            if ( values[j] > i) continue;
            dp[i] = min(dp[i], dp[i-values[j]] + 1);
        }
        if ( dp[i] > m){
            printf ("%d\n", i-1);
            break;
        }
    }



    return 0;
}
