
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

int start[1000001];
int end[1000001];

int main(void){
    int n, a, b, maxyIdle = 0, maxyBusy = 0, idleStart =0, busyStart =0, cnt = 0, limit = 0, begin = 1e6+10;

    scanf ("%d", &n);

    for (int i=0;i<n;++i){
        scanf ("%d %d", &a, &b);
        ++start[a];
        ++end[b];
        limit = max(limit, b);
        begin = min(begin, a);
    }

    idleStart = begin;

    for (int i=begin;i<=limit;++i){

        if ( start[i] > 0 ){
            if ( cnt == 0 ) {
                busyStart = i;
                maxyIdle = max(maxyIdle, i - idleStart);
            }
            cnt+=start[i];
        }

        if ( end[i] > 0 ){
            cnt-=end[i];
            if ( cnt == 0){
                idleStart = i;
                maxyBusy = max(maxyBusy, i - busyStart);
            }
        }

    }
    printf ("%d %d\n", maxyBusy, maxyIdle);
    return 0;
}
