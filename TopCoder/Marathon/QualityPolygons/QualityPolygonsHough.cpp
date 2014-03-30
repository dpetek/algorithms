#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <sys/time.h>
#include "opencv/cv.h"
#include "opencv/highgui.h"

#define pb push_back
#define fs first
#define sc second
using namespace std;
using namespace cv;

#define TIME_LIMIT 9.2

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

inline double currentTime(){
        return _gettime() - __startTime;
    }


vector <pair<int, int> > points;
vector<pair<double, int> > neighbours[5005];

int accField[500][500][200];

inline double angle(pair<int, int> &pt){
    if ( pt.fs > 0 ){
        if ( pt.sc >= 0 ) return atan(1.0*pt.sc/pt.fs);
        else return atan(1.0 * pt.sc / pt.fs) + 2.0 * M_PI;
    }
    if ( pt.fs == 0 ){
        if ( pt.sc == 0 ) return 0.0;
        return 3.0 * M_PI / 2.0;
    }

    return atan(1.0*pt.sc / pt.fs) + M_PI;
}

bool cmpAngle (const int &a, const int &b){
    return angle(points[a]) < angle(points[b]);
}


class QualityPolygons{
    public:

        double calcDist(pair<int, int> &p1, pair<int,int> &p2){
            return sqrt( 1.0 * (p1.fs - p2.fs) * (p1.fs - p2.fs) + (p1.sc - p2.sc) * (p1.sc - p2.sc));
        }

        double calcDist(pair<int, int> &p1, pair<double, double> &p2){
            return  sqrt(1.0 * (p1.fs - p2.fs) * (p1.fs - p2.fs) + (p1.sc - p2.sc) * (p1.sc - p2.sc));
        }

        bool polyOK(vector<int> &v){
            if ( v.size() > 3 )
                sort(v.begin(), v.end(), cmpAngle);

            double minySide = 1e20, maxySide = 0;

            double tx = 0.0, ty = 0.0;
            for (int i=0;i<v.size();++i){
                tx += points[v[i]].fs;
                ty += points[v[i]].sc;
            }
            tx/=v.size();
            ty/=v.size();

            double minyRad = 1e20, maxyRad = 0.0;
            pair<double, double> mean = make_pair(tx, ty);
            for (int i=0;i<v.size();++i){
                double sDist = calcDist(points[v[i]], points[v[(i+1)%v.size()]]);
                minySide = min(minySide, sDist);
                maxySide = max(maxySide, sDist);
                double rDist = calcDist(points[v[i]], mean);
                minyRad = min(minyRad, rDist);
                maxyRad = max(maxyRad, rDist);

            }
            return minyRad / maxyRad >= maxRadDiff && minySide / maxySide >= maxSidesDiff;
        }


        double maxSidesDiff, maxRadDiff;
        vector <string> choosePolygons(vector <int> pts, int sidesDiff, int radiiDiff){
            startTimer();

            maxSidesDiff = 1.0 - 1.0*sidesDiff / 100.0;
            maxRadDiff = 1.0 - 1.0*radiiDiff / 100.0;

            IplImage *img = cvCreateImage(cvSize(700, 700), IPL_DEPTH_8U, 1);
            cvSet(img, cvScalar(0, 0, 0));

            for (int i=0;i<pts.size()/2;++i){
                points.pb(make_pair(pts[2*i], pts[2*i+1]));
                cvCircle(img, cvPoint(pts[2*i], pts[2*i+1]), 1, cvScalar(255,255,255), -1,8);
            }

            vector<Vec3f> circles;
            HoughCircles(img, circles, CV_HOUGH_GRADIENT,
                            1, 4 );
            for( size_t i = 0; i < circles.size(); i++ )
            {
                 Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
                 int radius = cvRound(circles[i][2]);
                 // draw the circle center
                 cvCircle( img, center, 3, Scalar(255,255,255), -1, 8, 0 );
                 // draw the circle outline
                 cvCircle( img, center, radius, Scalar(255,255,255), 1, 8, 0 );
            }

            cvShowImage("window", img);
            cvWaitKey();



            vector<string> ret;

            return ret;
        }
};

int main(void){
    cvNamedWindow("window");
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
