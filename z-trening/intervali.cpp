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

int dp[5005];
vector<pair<int,int> > intervals;

bool cmp(const pair<int,int> &p1, const pair<int,int> &p2){
    if ( p1.fs != p2.fs) return p1.fs < p2.fs;
    return p1.sc < p2.sc;
}



int main(void){
    int n, a, b;

    scanf("%d", &n);

    for (int i=0;i<n;++i){
        scanf("%d %d", &a, &b);
        intervals.pb(make_pair(a,b));
    }

    sort(intervals.begin(), intervals.end(), cmp);
    int maxy = 0;
    dp[0] = 1;
    for (int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if ( intervals[i].fs >= intervals[j].sc ) dp[i] = max(dp[i], dp[j]+1);
        }
        maxy = max(maxy, dp[i]);
    }
    printf ("%d\n", maxy);
    return 0;
}
