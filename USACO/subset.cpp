/*
ID: dpetek11
LANG: C++
TASK: subset
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
long long dpPrev[391][391];
long long dp[391][391];

int main(void){
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);

    int n;

    scanf ("%d", &n);
    int sum = n * (n+1) / 2;
    dpPrev[0][1] = 1LL;
    dpPrev[1][0] = 1LL;

    for (int i=2;i<=n;++i){
        for (int j=0;j<=390;++j){
            for (int k=0;k<=390;++k){

                if ( dpPrev[j][k] ){
//                    printf (" [%d %d %d] = %d\n", i-1, j, k, dp[i-1][j][k]);
                    if ( j + i <= 390 ) dp[j+i][k]+=dpPrev[j][k];
                    if ( k + i <= 390 ) dp[j][k+i]+=dpPrev[j][k];

//                    printf ("%d %d %d => %d\n", i, j+i, k, dp[i][j+i][k]);
//                    printf ("%d %d %d => %d\n", i, j, k+i, dp[i][j][k+i]);
                }
            }
        }

        for (int j=0;j<=390;++j){
            for (int k=0;k<=390;++k){
                dpPrev[j][k] = dp[j][k];
            }
        }
    }

    if ( sum % 2 == 1) printf ("%d\n", 0);
    else
    printf("%lld\n", dp[sum/2][sum/2] / 2);

    return 0;
}
