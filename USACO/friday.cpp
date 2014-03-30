/*
ID: dpetek11
LANG: C++
TASK: friday
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

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int cnt[15];

bool isLeap(int y){
    if ( y % 100 == 0 && y % 400 != 0 ) return false;
    if ( y % 4 == 0 ) return true;
    return false;
}

int main(void){
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
	int n;

	scanf ("%d", &n);

	int d = 3, m = 1, y = 1900;


    while ( true ){
        if (m == 1 && y == 1900 + n) break;
        cnt[(d-2<=0) ? (d+5) : (d-2)]++;

        if ( m == 2 ){
            d += isLeap(y);
        }else if (m == 12){
            ++y;
        }

        d += days[m] - 1;
        d = d % 7 + 1;
        m++;
        if ( m > 12) m = 1;
    }

    for (int i=1;i<=7;++i){
        printf ("%s%d",(i==1) ? "" : " ", cnt[i]);
    }
    printf ("\n");


    return 0;
}
