/*
ID: dpetek11
LANG: C++
TASK: fact4
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

const long long MOD = 1e5;

int main(void){
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);

	int n;

	scanf("%d", &n);

	int fact  =1;
	for (int i=1;i<=n;++i){
        fact*=i;
        while(fact%10==0)fact/=10;
        fact%=MOD;
	}
	while((fact%10)==0)fact/=10;

    printf ("%d\n", (fact%MOD)%10);
    return 0;
}
