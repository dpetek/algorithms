/*
ID: dpetek11
LANG: C++
TASK: numtri
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

int n;
int board[1002][1002];
int dp[1002][1002];

int main(void){
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);

    scanf("%d", &n);

    for (int i=0;i<n;++i){
        for(int j=0;j<=i;++j){
            scanf("%d", &board[i][j]);
        }
    }

    for (int row = n -1;row>=0;--row){
        for (int col=0;col<=row;++col){
            dp[row][col] = board[row][col] + max(dp[row+1][col], dp[row+1][col+1]);
        }
    }
    printf ("%d\n", dp[0][0]);
    return 0;
}
