#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#define pb push_back
#define fs first
#define sc second

using namespace std;

long long offset[8][2] = {
    {0LL, 1LL},
    {0LL, -1LL},
    {1LL, 0LL},
    {-1LL, 0LL},
    {1LL, 1LL},
    {1LL, -1LL},
    {-1LL, 1LL},
    {-1LL, -1LL}
};

vector<pair<long long,long long> > points;
int main(void){
    long long n;
    long long a, b;
    scanf("%lld", &n);
    long long sumX = 0LL, sumY = 0LL;
    for (int i=0;i<n;++i){
        scanf("%lld %lld", &a, &b);
        points.push_back(make_pair((long long)(a+b),(long long)(a-b)));
        long long x = a + b;
        long long y = a - b;
        sumX+=x;
        sumY+=y;
    }
    long long avgX = sumX / n;
    long long avgY = sumY / n;

    vector<pair<long long, long long> > avg;
    avg.pb(make_pair(avgX, avgY));
    for (int i=0;i<8;++i){
        avg.pb(make_pair(avgX + offset[i][0], avgY + offset[i][1]));
    }


    long long miny = -1LL;
//    int index;

    vector<int> candidates;
    int index;
    set<pair<long long, int> > best;
    miny = -1LL;
    for (int i=0;i<n;++i){
        long long dist = abs(avgX - points[i].fs) + abs(avgY- points[i].sc);

        if ( best.size() < 200){
            best.insert(make_pair(-dist, i));
        }else{
            long long tmpDist = -best.begin()->fs;
            if ( dist < tmpDist ){
                best.erase(best.begin());
                best.insert(make_pair(-dist, i));
            }
        }
    }

    long long minySum = -1LL;

    for (set<pair<long long,int> > :: iterator it = best.begin(); it != best.end(); ++it){
        long long X = points[it->sc].fs;
        long long Y = points[it->sc].sc;
        long long totalSum = 0LL;
        for (int i=0;i<n;++i){
            totalSum += abs(X - points[i].fs) + abs(Y - points[i].sc);
        }
        if ( minySum == -1LL || totalSum < minySum){
            minySum = totalSum;
        }
    }


    printf ("%lld\n", minySum/2LL);


	return 0;
}
