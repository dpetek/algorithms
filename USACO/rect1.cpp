/*
ID: dpetek11
LANG: C++
TASK: rect1
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

class Rect{
    public:
        int x1, y1, x2, y2;
        int color;
        Rect(int xx1,int  yy1,int xx2,int yy2, int c): x1(xx1), x2(xx2),y1(yy1),y2(yy2),color(c){}

        int area(){
            return (x2-x1) * (y2-y1);
        }

        Rect overlap(Rect r){
            int ox1 = max(x1,r.x1);
            int ox2 = min(x2,r.x2);
            int oy1 = max(y1,r.y1);
            int oy2 = min(y2,r.y2);
            if ( ox2 <= ox1 || oy2 <= oy1) return Rect(0,0,0,0,-1);
            return Rect(ox1,oy1,ox2,oy2,r.color);
        }

        vector<Rect> split(const Rect &r){
            vector<Rect> ret;
            Rect ov = this->overlap(r);
            if ( ov.area() <= 0){ // no overlaping
                ret.pb(*this);
                return ret;
            }else if(ov.area() == this->area()){ // full overlaping
                return ret;
            }else{
                if ( y1 < ov.y1 ) ret.pb(Rect(x1,y1,x2,ov.y1,color));
                if ( y2 > ov.y2 ) ret.pb(Rect(x1,ov.y2,x2,y2,color));
                if ( x1 < ov.x1 ) ret.pb(Rect(x1,ov.y1,ov.x1,ov.y2,color));
                if ( x2 > ov.x2 ) ret.pb(Rect(ov.x2,ov.y1,x2,ov.y2,color));
                return ret;
            }
        }

        string toStr(){
            char tmp[30];
            sprintf(tmp, "[%d %d] - [%d %d] [%d]", x1, y1, x2, y2, color);
            return tmp;
        }
};

int cnt[2501];

vector<Rect> rects;
vector<Rect> buffer;
int main(void){
    freopen("rect1.in", "r", stdin);
    freopen("rect1.out", "w", stdout);
    int w, h, n, x1, y1, x2, y2, c;

    scanf("%d %d %d", &w, &h, &n);

    rects.pb(Rect(0,0,w,h,1));

    for (int i=0;i<n;++i){
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        Rect newRect(x1,y1,x2,y2,c);
        buffer.clear();
        for(int i=0;i<rects.size();++i){
            vector<Rect>tmp = rects[i].split(newRect);
            copy(tmp.begin(), tmp.end(), back_inserter(buffer));
        }
        buffer.pb(newRect);
        rects=buffer;
    }

    for (int i=0;i<rects.size();++i){
        cnt[rects[i].color]+=rects[i].area();
    }

    for (int i=1;i<=2500;++i){
        if ( cnt[i] ) {
            bool ok = true;
            printf ("%d %d\n", i, cnt[i]);
        }
    }

    return 0;
}
