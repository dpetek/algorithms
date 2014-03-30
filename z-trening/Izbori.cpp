#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define fs first
#define sc second

using namespace std;

vector<long long> v;

int main(void){
    int n;
    long long a;
    scanf("%d", &n);

    if ( n == 0 ){
        printf ("%d\n", 0);
        return 0;
    }

    for (int i=0;i<n;++i){
        scanf("%lld", &a);
        v.pb(a);
    }

    sort(v.begin(), v.end());

    long long totalSum = 0LL;
    for (int i=0;i*2<=v.size();++i){
        if ( v[i] == 0LL) continue;

        totalSum+=v[i] / 2LL + 1LL;
    }
    printf("%lld\n", totalSum);

    return 0;
}
