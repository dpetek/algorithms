#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <queue>
#include <cmath>
#include <sys/time.h>

#define pb push_back
#define fs first
#define sc second
using namespace std;

#define TIME_LIMIT 230.0
#define TIME_LIMIT2 240.0

double __startTime;

double _gettime() {
        timeval time;
        gettimeofday(&time,0);
        return (double)time.tv_sec + ( (double)time.tv_usec / 1e6 );
    }
inline void startTimer(){
        __startTime = _gettime();
    }
inline bool timePassed(){
        return _gettime() - __startTime > TIME_LIMIT;
    }
inline bool timePassed2(){
        return _gettime() - __startTime > TIME_LIMIT2;
    }
inline double currentTime(){
        return _gettime() - __startTime;
    }

bool cmpVertices(const vector<int> &v1, const vector<int> &v2){
    return v1.size() > v2.size();
}

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
            return  (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) ;
        }

        double dist(const pair<double, double> &p){
            return (x - p.fs) * (x - p.fs) + (y - p.sc) * (y - p.sc);
        }

        double dist2 (const Point &p){
            return dist(p);

        }

        int cross(const Point &p){
            return x * p.y - y * p.x;
        }

};

int horisontal_bound;
int vertical_bound;

vector <Point> points;
vector<vector<int> > clusters;
vector<bool> pointUsed;

map<vector<int>, bool > triangleUsed;
map<vector<int>, bool > shapeUsed;

vector<bool> status;
vector<Point> center;
vector<double> radius;
vector<int> pointsLeft;
vector<int> pointsLeftQuadrants[5];

vector<int> find_polygon(vector<int> &v){
    if ( v.size() < 3 ) return vector<int>();
    int curr = v[0];
    vector<int> new_order;
    vector<bool> used(v.size(), false);
    double minyDist = 1e20, maxyDist = -1e10;

    for (int i=0;i<v.size();++i){
        if ( points[v[i]].x < points[curr].x ){
            curr = v[i];
        }
    }

    int start = curr;

    do{
        int n = -1, nInd;
        double dist = 1e30;
        bool found = false;
        for (int i=0;i<v.size();++i){
            if ( v[i] == curr ) continue;
            if ( used[i] ) continue;

            if ( n == -1 ) {
                n = v[i];
                nInd = i;
            }

            Point dif1 = points[v[i]] - points[curr];
            Point dif2 = points[n] - points[curr];
            int cross = dif1.cross(dif2);
            double d = dif1.dist(dif2);

            if ( cross < 0 ){
                n = v[i];
                nInd = i;
                dist = d;
            }else if ( cross == 0 ){

                if ( d < dist ){
                    dist = d;
                    n = v[i];
                    nInd = i;
                }
            }
        }
        new_order.pb(n);
        curr = n;
        used[nInd] = true;
    }while(curr != start );

    return new_order;
}

class QualityPolygons{
    private:
        int NUM_CLUSTERS;
        double maxSidesDiff, maxRadDiff;
        int max_cluster_size;
        double radius_ratio;
        double max_disp;
        int clustering_ratio;


    public:
        string vi2str(vector<int> &v){
            char tmp[1024];
            sprintf (tmp, "%d", v[0]);
            for (int i=1;i<v.size();++i) sprintf (tmp, "%s %d", tmp, v[i]);
            return tmp;
        }

        bool polyOK(vector<int> &v){
            if ( v.size() < 3 ) return false;

            double minySide = 1e20, maxySide = 0;

            double tx = 0.0, ty = 0.0;

            for (int i=0;i<v.size();++i){
                tx += points[v[i]].x;
                ty += points[v[i]].y;
            }
            tx/=v.size();
            ty/=v.size();

            double minyRad = 1e20, maxyRad = 0.0;
            pair<double, double> mean = make_pair(tx, ty);
            for (int i=0;i<v.size();++i){
                double sDist = points[v[i]].dist(points[v[(i+1)%v.size()]]);
                minySide = min(minySide, sDist);
                maxySide = max(maxySide, sDist);
                if ( minySide  < maxSidesDiff  * maxySide) return false;
                double rDist = points[v[i]].dist(mean);
                minyRad = min(minyRad, rDist);
                maxyRad = max(maxyRad, rDist);

            }
            return minyRad >= maxRadDiff * maxyRad && minySide >= maxSidesDiff * maxySide;
        }

        vector<int> makeItPretty(vector<int> v, int limit = 3){
            vector<int> maxyV;
            int maxySz = 0, pc;
            for (int mask=0;mask<(1<<v.size());++mask){
                pc = __builtin_popcount(mask);
                if ( pc < limit || pc > 6 ) continue;
                vector<int> tmp;
                for (int i=0;i<v.size();++i){
                    if ( mask & ( 1 << i )){
                        tmp.pb(v[i]);
                    }
                }
                if (polyOK(tmp)){
                    if ( tmp.size() > maxySz ){
                        maxySz = tmp.size();
                        maxyV = tmp;
                    }
                }
            }

            return maxyV;
        }

        void doClustering3(int base){
            if ( NUM_CLUSTERS > clusters.size()) {
                clusters.resize(NUM_CLUSTERS, vector<int>());
                center.resize(NUM_CLUSTERS);
                radius.resize(NUM_CLUSTERS);
            }

//            random_shuffle(pointsLeft.begin(), pointsLeft.end());
            for (int i=0;i<clusters.size();++i) clusters[i].clear();
            vector<bool> used(points.size(), false);

            int bucketSize = NUM_CLUSTERS / 4;


            // put 2 random points in each cluster
            for (int i=0;i<NUM_CLUSTERS;++i){
                int q;
                if ( i < bucketSize ) q = 0;
                else
                if ( i < 2*bucketSize ) q = 1;
                else
                if ( i < 3*bucketSize) q = 2;
                else q = 3;

                int tx = 0, ty = 0;
                for (int j=0;j<base;++j){
                    if ( pointsLeftQuadrants[q].size() < 4 ) continue;
                    int r = rand() % pointsLeftQuadrants[q].size();
                    int _s = r;
                    while (used[pointsLeftQuadrants[q][r]] ) {r = (r+1) % pointsLeftQuadrants[q].size(); if ( _s == r ) break;}
                    clusters[i].pb(pointsLeftQuadrants[q][r]);
                    used[pointsLeftQuadrants[q][r]]  = true;
                    tx+=points[pointsLeftQuadrants[q][r]].x;
                    ty+=points[pointsLeftQuadrants[q][r]].y;
                }
                if ( clusters[i].size() < base ) continue;


                Point p1 = points[clusters[i][0]];
//                Point p2 = points[clusters[i][1]];
                tx/=base;
                ty/=base;

                double dst = Point(tx, ty).dist(p1);
                radius[i] = dst;
                center[i] = Point(tx, ty);
            }


            for (int i=0;i<pointsLeft.size();++i){
                if ( used[pointsLeft[i]] ) continue;
                double miny = 1e20;
                int minyIndex = -1;

                int q;
                if ( points[pointsLeft[i]].x <horisontal_bound && points[pointsLeft[i]].y < vertical_bound) q = 0;
                if ( points[pointsLeft[i]].x >=horisontal_bound && points[pointsLeft[i]].y < vertical_bound) q = 1;
                if ( points[pointsLeft[i]].x <horisontal_bound && points[pointsLeft[i]].y >= vertical_bound) q = 2;
                if ( points[pointsLeft[i]].x >=horisontal_bound && points[pointsLeft[i]].y >= vertical_bound) q = 3;


                for (int j=0;j<bucketSize;++j){
                    int cl = q*bucketSize +  j;
                    if ( clusters[cl].size() > max_cluster_size ) continue;

                    double d = center[cl].dist(points[pointsLeft[i]]);
                    if ( abs(d - radius[cl] ) < miny ){
                        miny = abs(d - radius[cl]);
                        minyIndex = cl;
                    }
                }


                if ( minyIndex != -1 ){
//                    if (  min(miny, radius[minyIndex]) / max(miny, radius[minyIndex]) >= maxRadDiff / 1.2)
                        clusters[minyIndex].pb(pointsLeft[i]);
                }else break;
            }
        }

        void doClustering2(bool pure){
            if ( NUM_CLUSTERS > clusters.size()) {
                clusters.resize(NUM_CLUSTERS, vector<int>());
                center.resize(NUM_CLUSTERS);
                radius.resize(NUM_CLUSTERS);
            }

//            random_shuffle(pointsLeft.begin(), pointsLeft.end());
            for (int i=0;i<clusters.size();++i) clusters[i].clear();
            vector<bool> used(pointsLeft.size(), false);

            int bucketSize = NUM_CLUSTERS / 4;

            // put 2 random points in each cluster
            for (int i=0;i<NUM_CLUSTERS;++i){
                for (int j=0;j<2;++j){

                    int r = rand() % pointsLeft.size();
                    while ( used[r] ) r = (r+1)%pointsLeft.size();
                    clusters[i].pb(pointsLeft[r]);
                    used[r] = true;
                }

                Point p1 = points[clusters[i][0]];
                Point p2 = points[clusters[i][1]];

                int tx = (p1.x + p2.x) / 2;
                int ty = (p1.y + p2.y) / 2;

                double dst = Point(tx, ty).dist(p1);
                radius[i] = dst;
                center[i] = Point(tx, ty);
            }


            for (int i=0;i<pointsLeft.size();++i){
                if ( used[i] ) continue;
                double miny = 1e20;
                int minyIndex = -1;
                for (int j=0;j<clusters.size();++j){
                    if ( clusters[j].size() > max_cluster_size ) continue;

                    double d = center[j].dist(points[pointsLeft[i]]);
                    if ( abs(d - radius[j] ) < miny ){
                        miny = abs(d - radius[j]);
                        minyIndex = j;
                    }
                }


                if ( minyIndex != -1 ){
//                    if ( min(miny, radius[minyIndex]) / max(miny, radius[minyIndex]) >= maxRadDiff/1.2)
                        clusters[minyIndex].pb(pointsLeft[i]);
                }else break;
            }
        }

        void doClustering(bool pure){
            if ( NUM_CLUSTERS > clusters.size()) clusters.resize(NUM_CLUSTERS, vector<int>());
                for (int i=0;i<clusters.size();++i) clusters[i].clear();


                for (int i=0;i<pointsLeft.size();++i){
                    if ( pointUsed[pointsLeft[i]] ) continue;
                    int cluster = rand() % NUM_CLUSTERS;

                    if ( clusters[cluster].size() > 8) continue;

                    double disp = 0.0, avg = 0.0;

                    for (int j=0;j<clusters[cluster].size();++j){
                        avg+=points[clusters[cluster][j]].dist(points[pointsLeft[i]]);
                    }
                    if ( clusters[cluster].size() )
                        avg/=clusters[cluster].size();

                    for (int j=0;j<clusters[cluster].size();++j){
                        disp+= abs(points[clusters[cluster][j]].dist(points[pointsLeft[i]]) - avg);
                    }
                    if ( clusters[cluster].size())
                        disp/=clusters[cluster].size();

                    if ( disp > max_disp ) continue;

                    clusters[cluster].pb(pointsLeft[i]);
                }
        }

        vector<string> getTriangles(vector<int> pts){
            vector<string> ret;
            vector<bool> used(pts.size(), false);
            for (int p1=0;p1<pts.size();++p1){
                for (int p2=p1+1;p2<pts.size();++p2){
                    for (int p3=p2+1;p3<pts.size();++p3){
                        if ( used[p1] || used[p2] || used[p3] ) continue;

                        vector<int> tmp;tmp.pb(pts[p1]);tmp.pb(pts[p2]);tmp.pb(pts[p3]);

                        if ( polyOK(tmp) ){
                            used[p1] = used[p2] = used[p3] = true;
                            ret.pb(vi2str(tmp));
                        }
                    }
                }
            }
            return ret;
        }

        void normalizeShape(vector<int> &v){
            if ( v.size() < 3 ) return ;
            int miny = 1e6, minyIndex;

            for (int i=0;i<v.size();++i){
                if ( v[i] < miny ){
                    miny = v[i];
                    minyIndex = i;
                }
            }
            rotate(v.begin(), v.begin() + minyIndex, v.end());
        }

        vector <string> choosePolygons(vector <int> pts, int sidesDiff, int radiiDiff){
            startTimer();
            srand(time(0));
            vector<vector<int> > ret;

            maxSidesDiff = pow(1.0 - 1.0*sidesDiff / 100.0, 2.0);
            maxRadDiff = pow(1.0 - 1.0*radiiDiff / 100.0, 2.0);

            clusters.resize(NUM_CLUSTERS, vector<int>());

            for (int i=0;i<pts.size()/2;++i){
                points.pb(make_pair(pts[2*i], pts[2*i+1]));
            }

            clustering_ratio = 40;
            NUM_CLUSTERS = max((int)(points.size() / clustering_ratio), 5);
            max_cluster_size = 7;
            radius_ratio =8.0;

            horisontal_bound = rand() % 50 + 275;
            vertical_bound = rand() % 50 + 275;

            pointUsed.resize(points.size(), false);
            center.resize(NUM_CLUSTERS);
            radius.resize(NUM_CLUSTERS);
            for (int i=0;i<points.size();++i) pointsLeft.pb(i);


            if ( pointsLeft.size() > 4){
                if ( pointsLeft.size() > 50 )random_shuffle(pointsLeft.begin(), pointsLeft.end());
                int limit = min((int)pointsLeft.size(), 50);
                for (int p1=0;p1<limit;++p1){
                    if ( timePassed2()) break;
                    for (int p2=p1+1;p2<limit;++p2){
                        if ( timePassed2())break;
                       for (int p3=p2+1;p3<limit;++p3){
                            for (int p4=p3+1;p4<limit;++p4){
                                    if ( pointUsed[pointsLeft[p1]] ||
                                         pointUsed[pointsLeft[p2]] ||
                                         pointUsed[pointsLeft[p3]] ||
                                         pointUsed[pointsLeft[p4]])continue;

                                    vector<int>tmp;
                                    tmp.pb(pointsLeft[p1]);
                                    tmp.pb(pointsLeft[p2]);
                                    tmp.pb(pointsLeft[p3]);
                                    tmp.pb(pointsLeft[p4]);

                                    vector<int> vvv  = makeItPretty(find_polygon(tmp));

                                    if ( vvv.size() < 4)continue;
                                    ret.pb(vvv);
                                    for (int i=0;i<vvv.size();++i)pointUsed[vvv[i]]=true;
                            }
                        }
                    }
                }
            }
            pointsLeft.clear();
            for (int i=0;i<points.size();++i) if ( !pointUsed[i])pointsLeft.pb(i);
            for (int i=0;i<pointsLeft.size();++i) {
                if ( !pointUsed[pointsLeft[i]]) {
                    if ( points[pointsLeft[i]].x <horisontal_bound && points[pointsLeft[i]].y < vertical_bound) pointsLeftQuadrants[0].pb(pointsLeft[i]);
                    if ( points[pointsLeft[i]].x >=horisontal_bound && points[pointsLeft[i]].y < vertical_bound) pointsLeftQuadrants[1].pb(pointsLeft[i]);
                    if ( points[pointsLeft[i]].x <horisontal_bound && points[pointsLeft[i]].y >= vertical_bound) pointsLeftQuadrants[2].pb(pointsLeft[i]);
                    if ( points[pointsLeft[i]].x >=horisontal_bound && points[pointsLeft[i]].y >= vertical_bound) pointsLeftQuadrants[3].pb(pointsLeft[i]);
                }

            }


            vector<vector<int> > foundInIter;

            int addedInProcess = 0, numIterations=0;

            double iterStartTime = currentTime();
            int fastLimit = 10, cntIdle = 0, maxyAddedInProcess = 0;
            vector<vector<int> > iterBuffer;



            while (true){
                double _ctime = currentTime();
                if ( timePassed()) break;


                double stime = currentTime();
                this->doClustering2(false);

                numIterations++;

                bool foundInIter = false;

                bool foundSomething = false;
                for (int i=0;i<NUM_CLUSTERS;++i){
                    if ( clusters[i].size() < 3 ) continue;

                    vector<int> tmp = makeItPretty(find_polygon(clusters[i]), 3);

                    if ( tmp.size() < 3 ) continue;

                    foundSomething = true;

                    for (int j=0;j<tmp.size();++j) {
                        pointUsed[tmp[j]] = true;
                    }
                    addedInProcess+=tmp.size() * tmp.size();
                    ret.pb(tmp);
                }

                horisontal_bound = rand() % 50 + 275;
                vertical_bound = rand() % 50 + 275;

                vector<int> pl;
                for (int i=0;i<5;++i) pointsLeftQuadrants[i].clear();
                for (int i=0;i<pointsLeft.size();++i) {
                    if ( !pointUsed[pointsLeft[i]]) {
                        if ( points[pointsLeft[i]].x <horisontal_bound && points[pointsLeft[i]].y < vertical_bound) pointsLeftQuadrants[0].pb(pointsLeft[i]);
                        if ( points[pointsLeft[i]].x >=horisontal_bound && points[pointsLeft[i]].y < vertical_bound) pointsLeftQuadrants[1].pb(pointsLeft[i]);
                        if ( points[pointsLeft[i]].x <horisontal_bound && points[pointsLeft[i]].y >= vertical_bound) pointsLeftQuadrants[2].pb(pointsLeft[i]);
                        if ( points[pointsLeft[i]].x >=horisontal_bound && points[pointsLeft[i]].y >= vertical_bound) pointsLeftQuadrants[3].pb(pointsLeft[i]);

                        pl.pb(pointsLeft[i]);
                    }

                }
                pointsLeft = vector<int>(pl);
                random_shuffle(pointsLeft.begin(), pointsLeft.end());

                NUM_CLUSTERS = max((int)pointsLeft.size() / clustering_ratio,5);

                if ( pointsLeft.size() < 4 * NUM_CLUSTERS ) NUM_CLUSTERS = pointsLeft.size() / 4;
                if ( pointsLeft.size() < 3 ) break;
            }

//            for (int i=0;i<points.size();++i) pointUsed[i] = false;
//
//            for (int i=0;i<ret.size();++i)
//                for(int j=0;j<ret[i].size();++j)pointUsed[ret[i][j]] = true;

            fprintf(stderr, "Points left: %d\n", pointsLeft.size());


            vector<string> final;
            int cnt[40] = {0};
            int total = 0;

            for (int i=0;i<ret.size();++i){
                if ( !polyOK(ret[i]) ) continue;
                vector<int> _p = find_polygon(ret[i]);
                if (_p.size() != ret[i].size() || !polyOK(_p)) continue;
                ++cnt[_p.size()];
                ++total;
                final.pb(vi2str(ret[i]));
            }

            for (int i=3;i<20;++i){
                if ( cnt[i] ) fprintf (stderr, "Polygon [%d]: %d\n", i, cnt[i]);
            }
            fprintf(stderr, "Total number of polygons found: %d\n", total);
            fprintf (stderr, "Result %d\n", addedInProcess);
            fprintf ( stderr, "Time passed: %lf. Iterations done: %d\n", currentTime(), numIterations);
            return final;
        }
};

int main(void){

    int n, tmp, sD, rD;
    vector<int> pts;

    scanf ("%d", &n);
    for (int i=0;i<n;++i){
        scanf("%d", &tmp);
        pts.pb(tmp);
    }
    scanf ("%d %d", &sD, &rD);
    vector <string> res = QualityPolygons().choosePolygons(pts, sD, rD);

    printf ("%d\n", res.size());
    for (int i=0;i<res.size();++i){
        printf ("%s\n", res[i].c_str());
    }
    fflush(stdout);


    return 0;
}
