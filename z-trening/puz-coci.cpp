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
    int a, b, v;

    scanf ("%d %d %d", &a, &b,&v);

    int goal = v - a;
    int delta = a - b;
    int base = (goal % delta) ? (goal/delta+1) : (goal/delta);

    printf ("%d\n", base + 1);


    return 0;
}
