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

class Point{
    public:
        int x,y;

        Point(): x(0), y(0){}
        Point(int _x, int _y) : x(_x), y(_y){}
        Point(pair<int, int> pt) : x(pt.fs), y(pt.sc){}

        Point operator +(const Point &p){
            return Point(x + p.x, y + p.y );
        }

        Point operator -(const Point &p){
            return Point(x - p.x, y - p.y);
        }

        double dist( const Point &p){
            return  sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
        }

        double dist2(const pair<double, double> &p){
            return (x - p.fs) * (x - p.fs) + (y - p.sc) * (y - p.sc);
        }

        double dist2 (const Point &p){
            return dist(p);

        }

        int cross(const Point &p){
            return x * p.y - y * p.x;
        }
};

vector<Point> v;
double dist[202][202];
int n, s;

double solve(){
    vector<double> mst;
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double,int> > > Q;
    vector<bool> used(n + 1, false);
    vector<int> prev(n+1, -1);
    vector<double> memoo(n+1, 1e20);
    Q.push(make_pair(0.0,3));

    while (!Q.empty()){
        int node = Q.top().sc;
        double dst = Q.top().fs;
        printf ("%d %d %lf\n",node, prev[node], dst);
        Q.pop();
        if ( prev[node] == -1)
            mst.pb(dst);
        else mst.pb(dist[node][prev[node]]);

        used[node] = true;

        for (int i=0;i<n;++i){

            if ( !used[i] ){
                printf (" %d -> %d  %lf\n", node, i, dst+dist[node][i]);
                if ( dst + dist[node][i] < memoo[i]){
                    Q.push(make_pair(dst + dist[node][i], i));
                    memoo[i] = dst + dist[node][i];
                    prev[i] = node;
                }
            }

        }

    }
    sort(mst.begin(), mst.end());
    return mst[s];
}

int main(void){
    int a, b;
    scanf ("%d %d", &s, &n);

    for (int i=0;i<n;++i){
        scanf("%d %d", &a, &b);
        v.pb(Point(a,b));
    }

    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            dist[i][j] = v[i].dist(v[j]);
        }
    }

    printf ("%.2lf\n",solve());
    return 0;
}
