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

class Movie{
    public:
        int start, end, value;
        Movie(int s, int e, int v) : start(s), end(e), value(v){}
};
int dp[100005];
vector<Movie> movies;
int prevIndex = -1;

void updatePrevIndex(int current){
    int tmpIndex = max(0, prevIndex), maxy = -1, newIndex=-1;

    while(tmpIndex < movies.size() && movies[tmpIndex].end < movies[current].start){

        if ( dp[tmpIndex] > maxy ){
            maxy = dp[tmpIndex];
            newIndex = tmpIndex;
        }
        ++tmpIndex;
    }
    prevIndex = newIndex;
}

bool cmp(const Movie &m1, const Movie &m2){
    if ( m1.start != m2.start) return m1.start < m2.start;
    return m1.end < m2.end;
}

int main(void){
    int n, a, b, c;

    scanf ("%d", &n);
    for (int i=0;i<n;++i){
        scanf ("%d %d %d", &a, &b, &c);
        movies.pb(Movie(a,b,c));
    }
    sort(movies.begin(), movies.end(), cmp);
    int maxy = 0;
    for (int i=0;i<movies.size();++i){
        updatePrevIndex(i);
        if ( prevIndex == -1 ){
            dp[i] = movies[i].value;
        }else{
            dp[i] = movies[i].value + dp[prevIndex];
        }
        maxy = max(maxy, dp[i]);
    }
    printf ("%d\n", maxy);
    return 0;
}
