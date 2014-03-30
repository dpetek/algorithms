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

int main(void){

    int n;

    scanf("%d", &n);

    int i = 1, cnt = 0, sz = 1;

    while(sz<n){sz<<=1;++cnt;}


    while(!(n&i)){i<<=1;--cnt;}

    printf ("%d %d\n", sz, cnt);

    return 0;
}
