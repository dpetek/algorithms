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

        double dist(pair<double, double> p){
            return  sqrt((x - p.fs) * (x - p.fs) + (y - p.sc) * (y - p.sc));
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
map<pair<int,int>, bool> memoo;
vector<Point> points;

bool cmp(const Point &p1, const Point &p2){
    return p1.x < p2.x;
}

bool sqOk( Point &p1, const Point &p2){
    if ( p1.y == p2.y ) return false;
    double centerX = (p1.x - p2.x) / 2;
    double centerY = abs(p1.y - p2.y) / 2;

    double deltaX = abs(p1.x - centerX);
    double deltaY = abs(p1.y - centerY);

    double nx1 = p1.x + deltaY;
    double nx2 = p1.x - deltaY;
    double ny1 = p1.y + deltaX;
    double ny2 = p1.y - deltaX;

    if ( nx1 - (int)nx1 > 1e-7 ) return false;
    if ( nx2 - (int)nx2 > 1e-7 ) return false;
    if ( ny1 - (int)ny1 > 1e-7 ) return false;
    if ( ny2 - (int)ny2 > 1e-7 ) return false;

    return memoo[make_pair((int)nx1, (int)ny1)] && memoo[make_pair((int)nx2, (int)ny2)];

}

int main(void){
    int a, b, n;

    scanf("%d", &n);

    for (int i=0;i<n;++i){
        scanf("%d %d", &a, &b);
        points.pb(Point(a,b));
        memoo[make_pair(a,b)] = true;
    }

    sort(points.begin(), points.end(), cmp);
    int cnt = 0;

    for (int i=0;i<points.size();++i){
        for (int j=0;j<i;++j){

            if ( points[i].y == points[j].y ){
                int delta = points[i].x - points[j].x;
                pair<int,int> upperLeft = make_pair(points[j].x, points[j].y + delta);
                pair<int,int> upperRight= make_pair(points[i].x, points[j].y + delta);
                if ( memoo[upperLeft] && memoo[upperRight]){
                    ++cnt;
//                    printf ("Found regular: (%d %d) - (%d %d)\n", points[i].x, points[i].y, points[j].x, points[j].y);
                }
            }else{
                if ( points[i].x == points[j].x ) continue;
                if ( sqOk(points[j],points[i])) {
//                    printf ("Found unregular: (%d %d) - (%d %d)\n", points[i].x, points[i].y, points[j].x, points[j].y);
                    ++cnt;
                }
            }

        }
    }
    printf("%d\n", cnt);
    return 0;
}
