/*
ID: dpetek11
LANG: C++
TASK: castle
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

int color[55][55];
int value[55][55];
int n, m, _currentColor = 2;

bool ok(int r,int c){
    if ( r < 0 || r >= n || c < 0 || c >= m) return false;
    return true;
}

int fil(int row, int col, int clr){
    int cnt = 0;
    queue<pair<int,int> > Q;

    Q.push(make_pair(row, col));

    while (!Q.empty()){
        int r = Q.front().fs;
        int c = Q.front().sc;
        Q.pop();

        if ( color[r][c] == clr) continue;
        color[r][c] = clr;
        ++cnt;

        if ( !(value[r][c] & 1) && ok(r,c-1)) Q.push(make_pair(r,c-1));
        if ( !(value[r][c] & 2) && ok(r-1,c)) Q.push(make_pair(r-1,c));
        if ( !(value[r][c] & 4) && ok(r,c+1)) Q.push(make_pair(r,c+1));
        if ( !(value[r][c] & 8) && ok(r+1,c)) Q.push(make_pair(r+1,c));
    }
    return cnt;
}

pair<int, int> findMax(){
    int rooms = 0, maxySize = 0;
    ++_currentColor;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if ( color[i][j] != _currentColor){
                int tmp = fil(i, j, _currentColor);
                maxySize = max(maxySize, tmp);
                ++rooms;
            }
        }
    }

    return make_pair(rooms, maxySize);
}

int main(void){
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);

    scanf("%d %d", &m, &n);

    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            scanf("%d",&value[i][j]);
        }
    }
    _currentColor = 1;
    pair<int,int> preMax = findMax();
    printf ("%d\n", preMax.fs);
    printf ("%d\n", preMax.sc);

    pair<int,int> wallPos;
    int wallDir;
    int maxySize = 0;

    for (int i=0;i<n;++i){
        for(int j=0;j<m;++j){

            for (int k=0;k<4;++k){
                if ( value[i][j] & (1<<k)){

                    if ( k == 0 && j ) value[i][j-1] ^= 4;
                    if ( k == 1 && i ) value[i-1][j] ^= 8;
                    if ( k == 2 && j+1<m) value[i][j+1] ^=1;
                    if ( k == 3 && i+1<n) value[i+1][j] ^= 2;
                    value[i][j] ^= (1<<k);

                    ++_currentColor;
                    int res = fil(i, j, _currentColor);

                    if ( res > maxySize){
                        maxySize = res;
                        wallPos = make_pair(i, j);
                        wallDir = k;
                    }else if ( res == maxySize ){
                        if ( j < wallPos.sc){
                            wallPos = make_pair(i,j);
                            wallDir = k;
                        }else if (j == wallPos.sc &&  i > wallPos.fs){
                            wallPos = make_pair(i,j);
                            wallDir = k;
                        }else if (j == wallPos.sc &&  i ==  wallPos.fs && k < wallDir){
                            wallPos = make_pair(i, j);
                            wallDir = k;
                        }
                    }
                    if ( k == 0 && j ) value[i][j-1] ^= 4;
                    if ( k == 1 && i ) value[i-1][j] ^= 8;
                    if ( k == 2 && j+1<m) value[i][j+1] ^=1;
                    if ( k == 3 && i+1<n) value[i+1][j] ^= 2;
                    value[i][j] ^= (1<<k);
                }
            }
        }
    }
    printf ("%d\n", maxySize);

    char dir;
    switch(wallDir){
        case 0: dir = 'W';break;
        case 1: dir = 'N';break;
        case 2: dir = 'E';break;
        case 3: dir = 'S';break;
    }
    printf ("%d %d %c\n", wallPos.fs + 1, wallPos.sc + 1, dir);
    return 0;
}
