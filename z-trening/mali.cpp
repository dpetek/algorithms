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

int cntA[105], cntB[105];
int tmpA[105], tmpB[105];


int main(void){

    int n, a, b;

    cin >> n;

    for (int i=0;i<n;++i){
        scanf("%d %d", &a, &b);
        ++cntA[a];
        ++cntB[b];

        for (int i=0;i<101;++i){
            tmpA[i] = cntA[i];
            tmpB[i] = cntB[i];
        }

        int ia = 0, ib = 100;
        int maxy = 0;

        while (ia <= 100 && ib > 0){
            while ( !tmpA[ia] && ia <= 101) ++ia;
            while ( !tmpB[ib] && ib >= 0 ) --ib;
            if ( ia > 100 || ib <= 0 ) break;
            if ( ia + ib > maxy ) maxy = ia + ib;
            if ( tmpA[ia] > tmpB[ib]){
                tmpA[ia] -= tmpB[ib];
                tmpB[ib] = 0;
                --ib;
            }else{
                tmpB[ib] -= tmpA[ia];
                tmpA[ia] = 0;
                ++ia;
            }
        }

        printf ("%d\n", maxy);

    }

	return 0;
}
