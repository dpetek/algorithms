#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#define pb push_back
#define fs first
#define sc second

using namespace std;
long long friendly;
vector<long long> unfriendly;

long long gcd(long long a, long long b){
    if ( b == 0LL) return a;
    return gcd(b, a%b);
}

void get_factors(long long n, vector<long long> &container){
    int sq = (int)(sqrt(n) + 2);
    for (int i=1;i<=sq;++i){
        if ( n % i == 0LL ){
            if ( i != 1) container.push_back((long long)i);
            container.push_back(n/i);
        }
    }
}

set<int> badFactors;

int main(void){
    int n;

    scanf("%d %lld", &n, &friendly);

    for (int i=0;i<n;++i){
        long long u;
        scanf("%lld", &u);
        long long g = gcd(friendly, u);
        if ( g == 1LL || badFactors.find(g) != badFactors.end()) {
            continue;
        }else{
            badFactors.insert(g);
        }
        unfriendly.push_back(u);
    }

    vector<long long> _factors;
    get_factors(friendly, _factors);

    vector<int> factors;
    for(int i=0;i<_factors.size();++i){
        if ( badFactors.find(_factors[i]) == badFactors.end()){
            factors.push_back(_factors[i]);
            badFactors.insert(_factors[i]);
        }
    }

    int cnt = 0;
    for (int i=0;i<factors.size();++i){
        bool ok = true;
        for (int j=0;j<unfriendly.size();++j){
            if ( unfriendly[j] % factors[i] == 0){
                ok = false;break;
            }
        }
        cnt+=ok;
    }
    printf ("%d\n", cnt);
	return 0;
}
