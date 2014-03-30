/*
ID: dpetek11
LANG: C++
TASK: calfflac
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

char buffer[256];
string line;
int n;

int moveRight(int i){
    ++i;
    while ( true ){
        if ( i == n ) return -1;
        if ( line[i] >= 'a' && line[i] <= 'z' ) return i;
        if ( line[i] >= 'A' && line[i] <= 'Z' ) return i;
        ++i;
    }
    return -1;
}

int moveLeft(int i){
    --i;
    while (true ){
        if ( i == -1) return -1;
        if ( line[i] >= 'a' && line[i] <= 'z') return i;
        if ( line[i] >= 'A' && line[i] <= 'Z') return i;
        --i;
    }
    return -1;
}

pair<int, int> findPalin(int l, int r, int cnt){
    int prev;
    while ( true ){
        if ( l == -1 || r == -1 ) break;
        if ( tolower(line[l]) != tolower(line[r]) ) break;
        prev = l;
        l = moveLeft(l);
        r = moveRight(r);
        cnt+=2;
    }

    return make_pair(cnt, prev);
}



int main(void){
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);

    while ( fgets(buffer, 250, stdin) ){
        line+=string(buffer);
    }


	n = line.size();
	pair<int,int> maxy = pair<int, int> (0, 0);

	for (int i=0;i<n;++i){
        if ( (line[i]>='a' && line[i]<='z') || (line[i] >= 'A' && line[i]<='Z')){
            pair<int,int> b1 = findPalin(moveLeft(i), i, 0);
            pair<int,int> b2 = findPalin(moveLeft(i) , moveRight(i), 1);
            if ( b1.fs > maxy.fs ){
                maxy = b1;
            }

            if ( b2.fs > maxy.fs){
                maxy = b2;
            }
        }
	}
    printf ("%d\n", maxy.fs);
    string res = "";
    int cnt = 0;

    for (int i=maxy.sc;cnt < maxy.fs;++i){
        res.pb(line[i]);
        cnt += (line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z');
    }
    printf ("%s\n", res.c_str());

    return 0;
}
