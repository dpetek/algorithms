#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include <cmath>
#define pb push_back
#define fs first
#define sc second

using namespace std;

vector<int> graph[10];

bool connected[10][10];

int main(void){

    int test;

    scanf ("%d", &test);

    for (int _test=0;_test<test;++_test){
        int n, m, tmp;

        scanf ("%d %d", &n, &m);
        vector <int> cx, cy;

        for (int i=0;i<n;++i) connected[i][(i+1)%n] = true;
        for (int i=0;i<m;++i) {scanf ("%d", &tmp);cx.pb(tmp);}
        for (int i=0;i<m;++i) {scanf ("%d", &tmp);cy.pb(tmp);}
        for (int i=0;i<m;++i) connected[cx[i]-1][cy[i]-1] = true;

        for (int c1=0;c1<8;++c1){
            for (int c2=0;c2<8;++c2){
                for (int c3=0;c3<8;++c3){
                    for (int c4=0;c4<8;++c4){
                        for (int c5=0;c5<8;++c5){
                            for (int c6=0;c6<8;++c6){
                                for (int c7=0;c7<8;++c7){
                                    for (int c8=0;c8<8;++c8){

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }


    }

    return 0;
}
