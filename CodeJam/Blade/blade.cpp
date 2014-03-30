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

vector<string> board;

int main(void){
    int tc;

    scanf ("%d", &tc);

    for(int test=1;test<=tc;++test){
        string tmp;
        int n, m, d;
        scanf ("%d %d %d", &n,&m, &d);
        board.clear();
        for (int i=0;i<n;++i){
            cin >> tmp;
            board.pb(tmp);
        }
        int maxy = -1;
        for (int row=0;row<n;++row){
            for (int col=0;col<m;++col){
                for (int sz=3;;sz+=2){
                    if ( row < sz/2 || col < sz/2 || row + sz/2 >= n || col + sz/2 >= m ) break;
                    double sumX = 0.0, sumY = 0.0;

                    for (int i=row - sz/2;i <= row + sz/2;++i){
                        for (int j=col - sz/2;j<= col + sz/2;++j){
                            if ( i == row - sz/2 && j == col - sz/2)continue;
                            if ( i == row - sz/2 && j == col + sz/2)continue;
                            if ( i == row + sz/2 && j == col + sz/2)continue;
                            if ( i == row + sz/2 && j == col - sz/2)continue;

                            sumX += 1.0 * (row - i) * (d + board[i][j] - '0');
                            sumY += 1.0 * (col - j) * (d + board[i][j] - '0');
                        }
                    }

                    if ( abs(sumX) < 1e-6 && abs(sumY) < 1e-6){
                        maxy = max(maxy, sz);
                    }
                }

                for (int sz=4;;sz+=2){
                    if (  row + sz >= n || col + sz >= m ) break;

                    double sumX = 0.0, sumY = 0.0;
                    for (int i=row;i < row + sz;++i){
                        for (int j=col;j< col + sz;++j){
                            if ( i == row && j == col)continue;
                            if ( i == row && j == col + sz - 1)continue;
                            if ( i == row + sz - 1 && j == col)continue;
                            if ( i == row + sz - 1 && j == col + sz - 1)continue;
                            int dx = i - row, dy = j - col;

                            if (dx < sz/2 ){
                                sumX += 1.0 * (dx - sz/2) * (d + board[i][j] - '0');
                            }else{
                                sumX += 1.0 * (dx - sz/2+1) * (d + board[i][j] - '0');
                            }

                            if (dy < sz/2 ){
                                sumY += 1.0 * (dy - sz/2) * (d + board[i][j] - '0');
                            }else{
                                sumY += 1.0 * (dy - sz/2+1) * (d + board[i][j] - '0');
                            }
                        }
                    }

                    if ( abs(sumX) < 1e-5 && abs(sumY) < 1e-5){
                        maxy = max(maxy, sz);
                    }

                }
            }
        }
        if ( maxy == -1 ) printf ("Case #%d: IMPOSSIBLE\n", test);
        else printf ("Case #%d: %d\n",test, maxy);
    }

    return 0;
}
