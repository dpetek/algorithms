/*
ID: dpetek11
LANG: C++
TASK: pprime
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

queue<int> Q;

bool isPrime(int n){

    if (n == 2) return true;
    if ( !(n & 1)) return false;

    for (int i=3;i*i<=n;i+=2){
        if ( n%i==0 ) return false;
    }
    return true;
}

int getPal(int n){
    int ret = n;
    while (n){
        ret = ret * 10 + n % 10;
        n/=10;
    }
    return ret;
}
int getPal2(int n){
    int ret = n;
    n/=10;
    while (n){
        ret = ret * 10 + n % 10;
        n/=10;
    }
    return ret;
}
vector<int> sol;

int main(void){
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    int a, b;
    scanf ("%d %d", &a, &b);

    for (int i=1;i<10000;++i){
        int p1 = getPal(i);
        int p2 = getPal2(i);

        if ( p1>=a && p2 <= b &&  isPrime(p1)) sol.pb(p1);
        if ( p2>=a && p2 <= b && isPrime(p2)) sol.pb(p2);
    }
    sort(sol.begin(), sol.end());

    for (int i=0;i<sol.size();++i) printf ("%d\n", sol[i]);

    return 0;
}
