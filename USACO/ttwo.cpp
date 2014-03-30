/*
ID: dpetek11
LANG: C++
TASK: ttwo
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

char buffer[15];
vector<string> board;
int N = 10, M = 10;

int memoo_farmer[12][12][5];
int memoo_cows[12][12][5];

int move[4][2]={
    {-1,0},
    {0,1},
    {1, 0},
    {0,-1}
};

bool ok (int x, int y){
    if ( x < 0 || x>=N) return false;
    if ( y < 0 || y>=N) return false;
    return board[x][y] != '*';
}

int main(void){
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);

	queue<pair<pair<pair<int,int>, pair<int,int> >,int> > Q;
    pair<int,int> _farmer;
    pair<int,int> _cows;

    for (int i=0;i<N;++i){
        scanf("%s", buffer);
        for (int j=0;j<M;++j){
            if ( buffer[j] == 'F') _farmer = make_pair(((i<<16) | j),0);
            if ( buffer[j] == 'C') _cows = make_pair  ((i<<16) | j,0);
        }

        board.pb(buffer);
    }

    Q.push(make_pair(make_pair(_farmer, _cows), 0));
    bool foundSol = false;
    while ( !Q.empty()){
        pair<int,int> farmer = Q.front().fs.fs;
        pair<int,int> cows = Q.front().fs.sc;
        int cnt = Q.front().sc;
        Q.pop();


        int fx = farmer.fs >> 16;
        int fy = farmer.fs & 0xFFFF;
        int cx = cows.fs >> 16;
        int cy = cows.fs & 0xFFFF;

        if ( fx == cx && fy == cy ){
            foundSol = true;
            printf("%d\n", cnt);
            break;
        }
        if ( cnt > 10000) break;


        int ffx, ffy, ccx, ccy, fm, cm;
        if ( ok ( fx + move[farmer.sc][0], fy + move[farmer.sc][1])){
            ffx = fx + move[farmer.sc][0];
            ffy = fy + move[farmer.sc][1];
            fm = farmer.sc;
        }else{
            ffx = fx;
            ffy = fy;
            fm = (farmer.sc+1)%4;
        }

        if ( ok (cx + move[cows.sc][0], cy + move[cows.sc][1])){
             ccx = cx + move[cows.sc][0];
             ccy = cy + move[cows.sc][1];
             cm = cows.sc;
        }else{
            ccx = cx;
            ccy = cy;
            cm = (cows.sc+1)%4;
        }

        farmer = make_pair( (ffx << 16) | ffy, fm);
        cows = make_pair ( (ccx << 16) | ccy , cm);
        Q.push(make_pair(make_pair(farmer, cows), cnt+1));
    }
    if ( !foundSol ){
        printf ("0\n");
    }
    return 0;
}
