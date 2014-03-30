/*
ID: dpetek11
LANG: C++
TASK: holstein
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

int vitamins[20][30];
int req[30];


int main(void){
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    int n, m;

    scanf("%d", &m);

    for (int i=0;i<m;++i){
        scanf("%d", req + i);
    }

    scanf("%d", &n);

    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            scanf("%d", &vitamins[i][j]);
        }
    }
    int miny = 1e7, minyMask;
    for (int mask=0;mask<(1<<n);++mask){
        vector<int> cnt(m, 0);
        for (int i=0;i<n;++i){
            if ( mask & ( 1 << i)){
                for (int j=0;j<m;++j){
                    cnt[j] += vitamins[i][j];
                }
            }
        }
        bool ok = true;
        for (int i=0;i<m;++i){
            if ( cnt[i] < req[i] ){
                ok = false;
                break;
            }
        }

        if ( ok ){
            if ( __builtin_popcount(mask)< miny ){
                miny = __builtin_popcount(mask);
                minyMask = mask;
            }
        }

    }

    printf("%d", __builtin_popcount(minyMask));

    for (int i=0;i<n;++i){
        if ( minyMask & ( 1 << i )) printf (" %d", i + 1);
    }
    printf ("\n");

    return 0;
}
