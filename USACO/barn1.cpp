/*
ID: dpetek11
LANG: C++
TASK: barn1
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

vector<pair<int, int> > gap;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return (a.sc - a.fs) > (b.sc - b.fs);
}

vector<int> stals;

int main(void){
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    int n,m,s, a, prev = 0, begin = 1e6, end = 0;

    scanf ("%d %d %d", &n, &m, &s);

    for (int i=0;i<s;++i){
        scanf("%d", &a);
        stals.pb(a);
        begin = min(begin,a);
        end = max(end, a);

    }
    sort(stals.begin(), stals.end());
    for (int i=0;i<stals.size();++i){
        if (i){
            gap.pb(make_pair(prev,stals[i]));
        }
        prev = stals[i];
    }

    sort(gap.begin(), gap.end(), cmp);
    int sum = end - begin + 1;

    for (int i=0;i<min((int)gap.size(), n-1);++i){
        sum-= (gap[i].sc - gap[i].fs - 1);
    }
    printf ("%d\n", sum);

    return 0;
}
