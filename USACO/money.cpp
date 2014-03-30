/*
ID: dpetek11
LANG: C++
TASK: money
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

long long dp[10005];
vector<int> coins;

int main(void){
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    int n, m, c;

    scanf ("%d %d", &m, &n);

    for (int i=0;i<m;++i){
        scanf("%d", &c);
        coins.pb(c);
    }
    dp[0] = 1LL;
    for (int i=0;i<coins.size();++i){
        for (int j=coins[i];j<=n;++j){
            dp[j]+=dp[j-coins[i]];
        }
    }
    printf ("%lld\n", dp[n]);
    return 0;
}
