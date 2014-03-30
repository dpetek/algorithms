#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#define pb push_back
#define fs first
#define sc second

using namespace std;
long long friendly;
vector<long long> unfriendly;
vector<long long> factors;

int main(void){
    int n;

    scanf("%d %lld", &n, &friendly);

    for (int i=0;i<n;++i){
        long long u;
        scanf("%d", &u);
        unfriendly.push_back(u);
    }

    for (long long i=1LL;i*i<=friendly;++i){
        if ( friendly % i == 0 ){
            factors.push_back(i);
            factors.push_back(friendly / i );
        }
    }

    int cnt = 0;
    for (int i=0;i<factors.size();++i){
        bool factorOK = true;
        for (int j=0;j<unfriendly.size();++j){
            if ( unfriendly[j] % factors[i] == 0){
                factorOK = false;
                break;
            }
        }
        if ( factorOK ) ++cnt;
    }

    printf ("%d\n", cnt);

	return 0;
}
