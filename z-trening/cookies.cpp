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

vector<int> box;

int solve(){
    bool turn = true; // true->mirko, false->slavko

    while(true){
        int maxy = 0, maxyIndex = -1;
        int minyOdd = 1e6, minyOddIndex = -1;
        for (int i=0;i<box.size();++i){
            if ( box[i] > maxy ){
                maxy = box[i];
                maxyIndex = i;
            }

            if ( box[i] % 2 == 1 && box[i] < minyOdd){
                minyOdd = box[i];
                minyOddIndex = i;
            }
        }
        if ( minyOddIndex == -1){
            --box[maxyIndex];
            if ( box[maxyIndex] == 0) return (turn) ? 1 : 2;
        }else{
            --box[minyOddIndex];
            if ( box[minyOddIndex] == 0) return (turn) ? 1 : 2;
        }

        turn = !turn;
    }

}

int main(void){
    box.clear();
    int n, tmp;
    for (int i=0;i<3;++i){
        scanf("%d", &n);
        box.clear();
        for (int j=0;j<n;++j){
            scanf("%d", &tmp);
            box.pb(tmp);
        }
        printf ("%d\n", solve());
    }
    return 0;
}
