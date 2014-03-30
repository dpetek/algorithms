#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define fs first
#define sc second

using namespace std;

vector<long long> v;

bool checkOk(long long n, long long m){
    long long toRemove = 0LL, freeSpace = 0LL;

    for (int i=0;i<v.size();++i){
        if ( v[i] > n){
            toRemove += v[i] - n;
        }else{
            if ( freeSpace < m )
                freeSpace += n - v[i];
        }
    }

    if ( toRemove > m ) return false;
    if ( toRemove > freeSpace ) return false;
    return true;
}

int main(void){
    int a;
    long long n, m;
    scanf("%lld %lld", &n, &m);

    for (int i=0;i<n;++i){
        scanf("%lld", &a);
        v.pb(a);
    }

    long long L = 0LL, H = 1000000001LL, M;

    for(int i=0;i<100;++i){
        M = (L + H) / 2LL;
        if ( !checkOk(M, m)) L = M + 1LL;
        else H = M;
    }
    printf ("%lld\n", M);

    return 0;
}
