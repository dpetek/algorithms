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

string m[4];
int n, maxy = 0;

void calc(){

    for (int w=1;w<n;++w){
            for (int h=1;h<n;++h){
                for (int i1=1;i1+h+1<n;++i1){
                    for (int i2=1;i2+h+1<n;++i2){
                        for (int i3=1;i3+w+1<n;++i3){
                            if ( m[0][i1] != m[2][i3] || m[2][i3+w] != m[1][i2])continue;
                            for (int i4=1;i4+w+1<n;++i4){
                                if ( m[0][i1] == m[2][i3] &&
                                     m[2][i3+w] == m[1][i2] &&
                                     m[1][i2+h] == m[3][i4+w] &&
                                     m[3][i4] == m[0][i1+h])
                                            maxy = max (maxy, (w-1) * (h-1));
                            }
                        }
                    }
                }
            }
        }

}

int main(void){
    scanf ("%d", &n);
    for (int i=0;i<4;++i) cin >> m[i];

    sort(m, m+4);

    do{
        calc();
    }while(next_permutation(m, m+4));
    printf ("%d\n", maxy);

    return 0;
}
