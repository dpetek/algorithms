/*
ID: dpetek11
LANG: C++
TASK: sprime
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

int my_pow(int a, int b){
    if ( b == 0 ) return 1;
    if ( b == 1 ) return a;

    int tmp = my_pow(a, b/2);
    if ( b % 2 == 1) return tmp * tmp * a;
    else return tmp * tmp;
}

bool isPrime(int n){
    if ( n == 1 ) return false;
    if (n == 2) return true;
    if ( !(n & 1)) return false;

    for (int i=3;i*i<=n;i+=2){
        if ( n%i==0 ) return false;
    }
    return true;
}

queue<int> Q;
vector<int> sol;

int main(void){
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);

    Q.push(2);
    Q.push(3);
    Q.push(5);
    Q.push(7);

    int d;

    scanf ("%d", &d);
    int limit = my_pow(10, d);

    while (!Q.empty()){
        int n = Q.front();
        Q.pop();

        if ( n >= limit ) continue;

        if ( n * 10 > limit) sol.pb(n);

        for (int i=1;i<10;i+=2){
            if ( isPrime(n * 10 + i )){
                Q.push(n * 10 + i);
            }
        }
    }

    sort(sol.begin(), sol.end());
    for (int i=0;i<sol.size();++i) printf ("%d\n", sol[i]);

    return 0;
}
