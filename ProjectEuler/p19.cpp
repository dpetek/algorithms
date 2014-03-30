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

int days[12] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool isLeap(int y){
    if ( y % 400 == 0 ) return true;
    if ( y % 100 == 0 ) return false;
    return (y%4) == 0;
}

int num_days(int m, int y){
    if ( m != 1 ) return days[m];
//    if ( isLeap(y)) printf ("is leap : %d\n", y);
    return days[m] + isLeap(y);
}

int main(void){
    int dw = 0, dm = 0,  m = 0, y = 1900;
    int cnt = 0;
    while ( true ){
        ++dm;
        if ( dm == num_days(m, y)){
            if ( m < 11 ) ++m;
            else{
                m = 0;
                ++y;
            }
            dm = 0;
        }
        dw = (dw+1) % 7;

        if ( y == 1987 && m == 3 && dm == 20 ) printf ("%d\n", dw);
        if ( dm == 0 && dw == 6 && y >= 1901) ++ cnt;
        if ( y == 2001 ) break;
    }

    printf ("%d\n", cnt);
	return 0;
}
