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

double a;
double b;


int main(void){


	cin >> a >> b;

    int n = (int)sqrt(b);

    for (int i=2;i<=n;++i){
        double l = log(b) / log(1.0 * i);

        int pw = (int)l;

        int tmp = 1;
        for (int j=0;j<pw;++j) tmp*=i;

        if ( tmp >= a && tmp <= b) {
            printf ("%d %d\n", i, pw);
            return 0;
        }

    }

	return 0;
}
