#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>

#define pb push_back
#define fs first
#define sc second

using namespace std;


vector<pair<double, double> > sX, sY;

bool cmpX(const pair<double,double> &a, const pair<double,double> &b){
    return a.sc < b.sc;
}

int main ( void ){
    double miny = 1e10, a, b;
    int n;

    scanf ("%d", &n);

    for (int i=0;i<n;++i){
        scanf ("%lf %lf", &a, &b);
        sX.pb(make_pair(b,a));
        sY.pb(make_pair(b,a));
    }

    sort (sX.begin(), sX.end(), cmpX);
    pair<double, double> exLow = sX[0];
    pair<double, double> exHigh = sX[sX.size()-1];


    for (int i=0;i<sX.size();++i){
        double X = - (sX[i].sc - exLow.sc) / (sX[i].fs - exLow.fs);
        miny = min(miny, X);
        X = - (sX[i].sc - exHigh.sc) / (sX[i].fs - exHigh.fs);
        miny = min(miny, X);
    }
    printf ("%.2lf\n", miny);
}
