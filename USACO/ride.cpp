/*
ID: dpetek11
LANG: C++
TASK: ride
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

#define MOD 47

int main(void){
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string s1, s2;
    int sum1 = 1, sum2 = 1;

    cin >> s1 >> s2;

    for (int i=0;i<s1.size();++i){
        sum1 *= (s1[i] - 'A' + 1);
        sum1 %= MOD;
    }
    for (int i=0;i<s2.size();++i){
        sum2 *= (s2[i] - 'A' + 1);
        sum2 %= MOD;
    }
    printf ("%s\n", (sum1==sum2) ? "GO" : "STAY");
    return 0;
}
