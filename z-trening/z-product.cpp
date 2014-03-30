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

const int MAX = 1024;
const int MOD = 10007;
int matrix[MAX+3][MAX+3];
int org[MAX+3][MAX+3];

int myPow(int a, int b){
    if ( !b ) return 1;
    if ( b == 1 ) return a;

    int tmp = myPow(a, b/2);
    if(b&1) return (((a * tmp)%MOD) * tmp)%MOD;
    return (tmp * tmp)%MOD;
}

int myDiv(int a, int b){
    return (a * myPow(b, MOD-2))%MOD;
}

int myMod(int v){
    if ( v < 0 ) v = (v%MOD + MOD)%MOD;
    v%=MOD;
    return v;
}

void updateDiv(int row , int col, int value){
    int r=row,c =col;
    while ( r < MAX){
        c = col;
            while(c < MAX){
                matrix[r][c] = myDiv(matrix[r][c] ,value);;
                c+=c&(-c);
            }
        r+=r&(-r);
    }
}

void update(int row, int col, int value){
    int r=row,c =col;

    if ( org[row][col] != 0) updateDiv(row, col, org[row][col]);

    while ( r < MAX){
        c = col;
            while(c < MAX){
//                printf ("%d %d\n", r, c);fflush(stdout);
                matrix[r][c] = (matrix[r][c] * value) % MOD;
                c+=c&(-c);
            }
        r+=r&(-r);
    }
}

int get(int row, int col){
    int res = 1;

    int r = row, c = col;

    while ( r > 0 ){
        c = col;
            while ( c > 0 ){
                res = (res * matrix[r][c])%MOD;
                c-=c&(-c);
            }
        r-=r&(-r);
    }
    return res;
}

int main(void){

    int n, r1, c1, r2, c2,com,v, m;

    scanf("%d %d", &n, &m);

    for (int i=0;i<MAX;++i)
        for(int j=0;j<MAX;++j)
            matrix[i][j] = 1;

    for (int i=0;i<m;++i){
        scanf("%d", &com);
        if ( com == 1){
            scanf("%d %d %d", &r1, &c1, &v);
            update(r1+1, c1+1, v);
            org[r1+1][c1+1] = v;
        }else{
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            int s1 = get(r1, c1);
            int s2 = get(r2+1, c2+1);
            int s3 = get(r1, c2+1);
            int s4 = get(r2+1, c1);
            printf ("%d\n", myMod(myDiv(myMod(myDiv(s2, s3)*s1), s4)));
        }
    }

    return 0;
}
