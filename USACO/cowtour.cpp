/*
ID: dpetek11
LANG: C++
TASK: cowtour
*/
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
        Point(int _x,int _y) : x(_x), y(_y){}
        double dist(const Point &p){
            return sqrt( 1.0*(p.x-x)*(p.x-x) + 1.0*(p.y-y)*(p.y-y));
        }
};

vector<Point> points;

double dist[200][200];
char buffer[200];
double maxDist[200];
int color[200];
int n;

void fill(int node, int clr){
    queue<int> Q;
    Q.push(node);
    while ( !Q.empty()){
        int c = Q.front();
        Q.pop();
        if ( color[c] ) continue;
        color[c] = clr;

        for (int i=0;i<n;++i){
            if ( dist[i][c] < 1e20 && !color[i]){
                Q.push(i);
            }
        }

    }
}

int main(void){
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);

    int a, b;

    scanf("%d", &n);

    for (int i=0;i<n;++i){
        scanf("%d %d", &a, &b);
        points.pb(Point(a,b));
    }
    for (int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            dist[i][j] = 1e30;

    for (int i=0;i<n;++i){
        scanf("%s", buffer);
        for (int j=0;j<n;++j){
            if ( buffer[j] == '0' ) continue;
            dist[i][j] = points[i].dist(points[j]);
            dist[j][i] = points[j].dist(points[i]);
//            printf ("%d] (%d %d)-(%d %d) %lf\n",i,  points[i].x, points[i].y, points[j].x, points[j].y, dist[i][j]);
        }
    }

    int curColor = 1;

    for (int i=0;i<n;++i){
        if ( !color[i] ) fill(i, curColor++);
    }

    for (int k=0;k<n;++k){
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                if ( color[i] != color[j] || color[i] != color[k] || color[j] != color[k] ) continue;
                if ( dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

            }
        }
    }

    for (int i=0;i<n;++i){
        double maxy = 0.0;
        for (int j=0;j<n;++j){
            if ( color[i] != color[j] ) continue;
            if ( i == j ) continue;
            if ( dist[i][j] < 1e20 && color[i] == color[j]){
                maxy = max(maxy, dist[i][j]);
            }
        }
        maxDist[i] = maxy;
    }

    double miny = 1e30;
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if ( color[i] == color[j] ) continue;
            double nd = maxDist[i] + points[i].dist(points[j]) + maxDist[j];
            for (int k=0;k<n;++k){
                if ( color[k] == color[i] || color[k] == color[j] ) nd=max(nd, maxDist[k]);
            }
//            printf ("(%d %d)-(%d %d) %lf\n", points[i].x, points[i].y, points[j].x, points[j].y, nd);
            miny = min(miny, nd);
        }
    }
    printf ("%.6lf\n", miny);
    return 0;
}
