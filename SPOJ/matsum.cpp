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
const int MAX=1027;
int matrix[MAX+10][MAX+10];
int org[MAX+1][MAX+1];
int timestamp[MAX+10][MAX+10];

void update(int row, int col, int value,int time){
    int dif = value - org[row][col];
    if ( dif ){
        int r = row, c = col;
        while ( r < MAX ){
            c = col;
            while ( c < MAX ){
                if ( timestamp[r][c] == time){
                    matrix[r][c] += dif;
                }else{
                    matrix[r][c] = dif;
                    timestamp[r][c] = time;
                }
                c+=c&(-c);
            }
            r+=r&(-r);
        }
    }
}

int get(int row, int col,int time){
    int r = row, c = col,sum = 0;

    while ( r > 0 ){
        c = col;
        while ( c > 0 ){
            if ( timestamp[r][c] == time)
                sum+=matrix[r][c];
            c-=c&(-c);
        }
        r-=r&(-r);
    }
    return sum;
}

int main(void){
    char command[10];
    int r1, c1, r2, c2, v, n, test;

    scanf("%d", &test);

    for (int _test=1;_test<=test;++_test){
        scanf("%d", &n);
        while ( true ){
            scanf("%s", command);
            if ( string(command) == "END") break;
            if ( string(command) == "SET"){
                scanf("%d %d %d", &r1, &c1, &v);
                update(r1+2, c1+2, v, _test);
                org[r1+2][c1+2] = v;
            }
            if ( string(command) == "SUM"){
                scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
                int s1 = get(r1+1, c1+1, _test);
                int s2 = get(r2+2, c2+2, _test);
                int s3 = get(r1+1, c2+2, _test);
                int s4 = get(r2+2, c1+1, _test);
                printf ("%d\n", s2 -s3 - s4 + s1);
            }
        }
    }

    return 0;
}
