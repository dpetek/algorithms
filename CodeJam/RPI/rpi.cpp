#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#define pb push_back
#define fs first
#define sc second

using namespace std;



int main(void){
    int test;

    scanf ("%d", &test);

    for (int _test=0;_test<test;++_test){
        int n;
        scanf ("%d", &n);

        string tmp;
        vector<string> board;
        for (int i=0;i<n;++i){
            cin >> tmp;
            board.pb(tmp);
        }
        vector <double> WP, OWP, OOWP;

        for (int team=0;team<n;++team){
            int numWin = 0, numLose = 0;
            for (int i=0;i<n;++i){
                if ( board[team][i] == '0' ) ++numLose;
                else if ( board[team][i] == '1') ++numWin;
            }
            WP.pb( (double)(numWin) / (double)(numWin+numLose));
        }

        for (int team=0;team<n;++team){
            int numOp = 0;
            double sum = 0.0;
            for (int i=0;i<n;++i){
                if ( board[team][i] != '.'){
                    ++numOp;
                    int numWin = 0, numLose = 0;
                    for (int j=0;j<n;++j){
                        if ( j == team ) continue;
                        if ( board[i][j] == '0' ) ++numLose;
                        else if ( board[i][j] == '1') ++numWin;
                    }
                    sum+=(double)(numWin) / (double)(numWin+numLose);
                }
            }
            OWP.pb( sum / (double)numOp);
        }

        for (int team=0;team<n;++team){
            int numOp = 0;
            double sum = 0.0;
            for (int i=0;i<n;++i){
                if ( board[team][i] != '.'){
                    ++numOp;
                    sum+=OWP[i];
                }
            }
            OOWP.pb( sum / (double)numOp);
        }
        printf ("Case #%d:\n", _test + 1);
        for (int i=0;i<n;++i) printf ("%lf\n", 0.25 * WP[i] + 0.50 * OWP[i] + 0.25 * OOWP[i]);

    }

    return 0;
}
