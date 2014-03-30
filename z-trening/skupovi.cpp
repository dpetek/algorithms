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
#define MOD 1000000007LL
int n ;
long long m;
long long num[100005];
map<long long, int> pos;

long long myPow(long long a, long long b){
    if ( b == 0LL) return 1LL;
    if ( b == 1LL) return a % MOD;

    long long tmp = myPow(a, b / 2LL) % MOD;
    if ( b%2LL == 0LL) return (tmp * tmp)%MOD;
    return (((a * tmp) %MOD)* tmp)%MOD;
}



int main(void){

    scanf ("%d %lld", &n, &m);
    for (int i=0;i<n;++i){
        scanf ("%lld", &num[i]);
    }

    sort(num, num+n);

    for (int i=0;i<n;++i){
        pos[num[i]] = i+1;
    }
    long long sum = 0LL;
    for (int i=0;m-num[i]>=num[i];++i){
        int position = pos[m-num[i]];

        if (position){
            if ( position -1 != i){
                sum+=myPow(2LL, (long long)(position - i - 2LL));
                sum%=MOD;
            }else{
                sum+=1LL;
            }
        }
    }
    printf ("%lld\n", sum%MOD);

    return 0;
}
