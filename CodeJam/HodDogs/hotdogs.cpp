#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include <cmath>
#define pb push_back
#define fs first
#define sc second

using namespace std;


int main(void){

    int test;

    scanf ("%d", &test);

    for (int _test=0;_test<test;++_test){
        int D, C, P, V;

        scanf ("%d %d", &C, &D);
        vector<int> stands;

        for (int i=0;i<C;++i){
            scanf ("%d %d", &P, &V);
            for (int i=0;i<V;++i) stands.pb(P);
        }
        double H = 210000000.0, L = 0.0, M;

        for (;;){
            M = (H+L)/2.0;

            double prev = -100000000000.0;
            bool ok = true;
            for (int j=0;j<stands.size();++j){
                double tmp1;

                if ( j )
                    tmp1 = max((double)stands[j] - M, prev + (double)D);
                else
                    tmp1 = stands[j]-M;

                if ( abs(tmp1 - stands[j] )> M){
                    ok = false;
                    break;
                }
                prev = tmp1;
            }

            if ( ok )H = M ;
            else L = M;
            if ( abs(H-L) < 1e-7) break;
        }
        printf ("Case #%d: %.2lf\n",_test + 1,  M);
    }


    return 0;
}
