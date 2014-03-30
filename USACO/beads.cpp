/*
ID: dpetek11
LANG: C++
TASK: beads
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

int main(void){
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
	string s;
	int maxy = 0, n;
    cin >> n;
	cin >> s;

	for (int i=0;i<s.size();++i){
        int leftIndex=i, rightIndex = (i+1)%s.size();
        int leftColor = s[leftIndex], rightColor = s[rightIndex];
        int cntLeft = 0, cntRight = 0;

        while ( true ){
            if ( leftColor == 'w' && s[leftIndex] != 'w'){
                leftColor = s[leftIndex];
            }
            if ( s[leftIndex] == 'w' || s[leftIndex] == leftColor){
                ++cntLeft;
            }else break;

            leftIndex = leftIndex - 1;
            if ( leftIndex < 0 ) leftIndex = s.size() -1;

            if ( cntLeft > s.size() ) break;
        }

        while ( true ){


            if ( rightColor == 'w' && s[rightIndex] != 'w'){
                rightColor = s[rightIndex];
            }
            if ( s[rightIndex]=='w' || s[rightIndex] == rightColor){
                ++cntRight;
            }else break;
            rightIndex = (rightIndex + 1) % s.size();
            if ( cntRight > s.size() ) break;
        }

        int cnt = min(cntLeft + cntRight , (int)s.size());
        maxy = max (maxy, cnt);

	}
    printf ("%d\n", maxy);

    return 0;
}
