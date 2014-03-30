#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#define pb push_back
#define fs first
#define sc second

using namespace std;

bool isIncreesing[1<<16];
vector<int> seq;
int memoo[1<<16];

void calcIncreesing(){
    for (int mask=0;mask<(1<<seq.size());++mask){
        int prev = -1;
        bool isInc = true;
        for (int i=0;i<seq.size();++i){
            if ( mask & ( 1 << i)){
                if (seq[i] > prev)isInc = true;
                else{
                    isInc = false;
                    break;
                }
                prev = seq[i];
            }
        }
        isIncreesing[mask] = isInc;
    }
}

int calcWinner(int state, int turn){
    int &ref = memoo[state];
    if ( ref != 0 ) return ref;
    if ( isIncreesing[state] ) return ref = 3 - turn;
    for (int i=0;i<seq.size();++i){
        if ( state & ( 1<<i)){
            if ( calcWinner(state ^ (1<<i), 3 - turn) == turn ) return ref = turn;
        }
    }
    return ref = 3 - turn;
}

int main(void){
    int _test, n, a;
#ifdef FILE_INPUT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    scanf ("%d", &_test);
    for (int t=0;t<_test;++t){
        scanf("%d", &n);
        seq.clear();
        for (int i=0;i<=(1<<n);++i) memoo[i] = 0;
        for (int i=0;i<n;++i){
            scanf("%d", &a);
            seq.push_back(a);

        }
        calcIncreesing();
        printf ("%s\n", calcWinner((1<<n)-1, 1) == 1 ? "Alice" : "Bob");
    }

	return 0;
}
