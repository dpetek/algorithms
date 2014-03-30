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

int dp[130][130][2], n;
int value[130];


int solve(int left, int right, int turn){
    int &ref = dp[left][right][turn];
    if ( ref ) return ref;


}

int main(void){

    scanf ("%d", &n);

    for(int i=0;i<n;++i){
        scanf("%d", &value[i]);
    }

    for (int i=0;i<n;++i){
        dp[i][i][0] = dp[i][i][1] = value[i];
    }

    solve(0, n-1, 0);

    return 0;
}
