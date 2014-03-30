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

vector <pair<pair<int,int> , int> > v;
vector<pair<pair<double, double>, pair<int, int> > > speed;
vector <pair<int, int> > all;

int main(void){
    int tc;

    scanf ("%d", &tc);

    for (int test=1;test<=tc;++test){
        int x, s, r, t, n, a, b, w;
        double res = 0.0;
        v.clear();
        speed.clear();
        all.clear();
        pair<int, int> prev= make_pair(0, 0);

        scanf ("%d %d %d %d %d", &x, &s, &r, &t, &n);

        for (int i=0;i<n;++i){
            scanf ("%d %d %d", &a, &b, &w);
            v.pb(make_pair(make_pair(a,b),w));
            if ( prev.sc != a){
                double running = 1.0 *( a - prev.sc) / r;
                double walking = 1.0 *( a - prev.sc) / s;
                speed.pb(make_pair(make_pair(running/walking, s), make_pair(prev.sc , a )));
                res+= walking;
            }
            double running = 1.0 * (b - a ) / (r+w);
            double walking = 1.0 * (b - a ) / (s+w);
            res+=walking;
            speed.pb(make_pair(make_pair(running/walking, s+w), make_pair(a, b )));
            prev = make_pair(a, b );
        }
        if ( prev.sc != x ){
            double running = 1.0 *( x - prev.sc) / r;
            double walking = 1.0 *( x - prev.sc) / s;
            speed.pb(make_pair(make_pair(running/walking, s), make_pair(prev.sc , x )));
            res+= walking;
        }
        sort(speed.begin(), speed.end());
        double timeLeft = t;


        for (int i=0;i<speed.size();++i){
            double t1 = 1.0 * (speed[i].sc.sc - speed[i].sc.fs) / speed[i].fs.sc;
            double t2 = t1 * (speed[i].fs.fs);
            if ( t2 < timeLeft ){
                res -= (t1 - t2);
                timeLeft -= t2;
            }else{
                double tt1 = timeLeft * (1.0 / speed[i].fs.fs);
                res -= (tt1 - timeLeft);
                break;
            }

        }
        printf ("Case #%d: %lf\n", test, res);
    }


    return 0;
}
