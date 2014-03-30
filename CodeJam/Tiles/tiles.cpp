#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#define pb push_back
#define fs first
#define sc second

using namespace std;
int mask[100][100];
int board[100][100];
int n , m;

bool ok ( int &x, int &y){
    if ( x < 0 || x+1 >= n ) return false;
    if ( y < 0 || y+1 >= m ) return false;
    if ( !mask[x][y] || !mask[x+1][y] || !mask[x][y+1] || !mask[x+1][y+1])return false;
    if ( board[x][y]>0 || board[x+1][y]>0 || board[x][y+1]>0 || board[x+1][y+1]> 0)return false;
    return true;
}

int move[4][2] = {
    {2, 0},
    {0, 2},
    {-2, 0},
    {0, -2},
};

void color(int _x, int _y){
    queue<pair<int, int> > Q;

    Q.push(make_pair(_x, _y));

    while ( !Q.empty()){
        int X = Q.front().fs;
        int Y = Q.front().sc;
        Q.pop();

        if ( !ok ( X, Y )) continue;
        board[X][Y] = board[X+1][Y+1] = 1;
        board[X+1][Y] = board[X][Y+1] = 2;

        for (int i=0;i<4;++i){
            int tmpX = X + move[i][0];
            int tmpY = Y + move[i][1];
            if ( !ok ( tmpX, tmpY)) continue;
            if ( board[tmpX][tmpY] > 0 ) continue;
        }


    }

}

int main ( void ){
    int test;
    scanf ("%d", &test);
    for (int _test=0;_test<test;++_test){

        scanf ("%d %d", &n, &m);
        string tmp ;

        for (int i=0;i<n;++i){
            cin >> tmp;
            for (int j=0;j<tmp.size();++j){
                if ( tmp[j] == '.' ) mask[i][j] = 0;
                else mask[i][j] = 1;
            }

        }
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
               board[i][j] = 0;
            }
        }

        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                if ( board[i][j] == 0 && mask[i][j] ==1) color(i, j);
            }
        }
        bool isOk = true;
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                if ( board[i][j] == 0 && mask[i][j] ==1) isOk = false;
            }
        }

        printf ("Case #%d:\n", _test+1);
        if ( isOk ){
            for (int i=0;i<n;++i){
                for (int j=0;j<m;++j){
                    if ( board[i][j] == 0 ) printf (".");
                    else if ( board[i][j] == 1 ) printf ("/");
                    else printf ("\\");
                }
                printf ("\n");
            }
        }else{
            printf ("Impossible\n");
        }

    }



    return 0;
}
