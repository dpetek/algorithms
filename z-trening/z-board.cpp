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

int ways[502][502], num;
char board[502][502];
int rows,cols;

int main(void){

    scanf("%d %d %d", &rows, &cols, &num);

    for (int i=0;i<rows;++i){
        scanf("%s", board[i]);
    }
    ways[rows-1][cols-1]=1;

    for (int row=rows-1;row>=0;--row){
        for (int col=cols-1;col>=0;--col){
            int sum = 0;
            if ( ways[row][col] > 0 ) continue;
            if ( board[row][col] == '#') continue;
            if (  board[row+1][col] != '#') sum+=ways[row+1][col];
            if (  board[row][col+1] != '#') sum+=ways[row][col+1];
            if ( sum > 1000000001) sum = 1000000001;
            ways[row][col]=sum;
        }
    }

    int row = 0, col = 0;
    string path = "";

    if ( ways[0][0] < num ){
        printf ("impossible\n");
        return 0;
    }

    while ( true ){

        if (row < rows - 1 && ways[row+1][col] >= num) {path+="D";++row;}
        else{
            path += "R";
            num-=ways[row+1][col];
            ++col;
        }
        if ( row == rows -1 && col == cols -1 ) break;
    }

    printf ("%s\n", path.c_str());
    return 0;
}
