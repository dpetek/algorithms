#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#define pb push_back
#define fs first
#define sc second

using namespace std;


class Rect{
    public:
        int x1, y1;
        int x2, y2;

    Rect(int x, int y, int n){
        x1 = x;
        y1 = y;
        x2 = x + n;
        y2 = y + n;
    }

    Rect(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2){}

    Rect overlap(Rect& r){
        int _x1 = max(x1, r.x1);
        int _y1 = max(y1, r.y1);
        int _x2 = min(x2, r.x2);
        int _y2 = min(y2, r.y2);

        if ( _x1 < _x2 && _y1 < _y2)
            return Rect(_x1, _y1, _x2, _y2);
        else
            return Rect(0,0,0);
    }

    int area(){
        return (x2 - x1) * (y2 - y1);
    }

};
vector<Rect> rects;
int main(void){

	return 0;
}
