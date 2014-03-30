/*
ID: dpetek11
LANG: C++
TASK: milk3
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

bool memoo[21][21][21];
int B[3];

class State{
    public:
        int b1, b2, b3;
        State(int a, int b, int c) {
            b1 = a;
            b2 = b;
            b3 = c;
        }

        vector<State> nextStates(){
            int sum, bb1, bb2, bb3;
            vector<State> ret;

                // b1 -> b2
                sum = b1 + b2; bb2 = min(B[1], sum);bb1 = sum - bb2;
                ret.pb(State(bb1, bb2, b3));
                // b1 -> b3
                sum = b1 + b3; bb3 = min(B[2], sum);bb1 = sum - bb3;
                ret.pb(State(bb1, b2, bb3));

                // b2 -> b1
                sum = b1 + b2; bb1 = min(B[0], sum);bb2 = sum - bb1;
                ret.pb(State(bb1, bb2, b3));
                // b2 -> b3
                sum = b2 + b3; bb3 = min(B[2], sum);bb2 = sum - bb3;
                ret.pb(State(b1, bb2, bb3));

                //b3 -> b1
                sum = b1 + b3; bb1 = min(B[0], sum);bb3 = sum - bb1;
                ret.pb(State(bb1, b2, bb3));
                //b3 -> b2
                sum = b2 + b3; bb2 = min(B[1], sum);bb3 = sum - bb2;
                ret.pb(State(b1, bb2, bb3));
                return ret;
        }
};

int main(void){
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);

    scanf ("%d %d %d", B, B+1, B+2);
    queue<State> Q;

    Q.push(State(0,0, B[2]));

    set<int> res;

    while ( !Q.empty()){
        State s = Q.front();
        Q.pop();
        if ( s.b1 == 0 ) res.insert(s.b3);
        if ( memoo[s.b1][s.b2][s.b3] ) continue;
        memoo[s.b1][s.b2][s.b3] = true;

        vector<State> states= s.nextStates();


        for (int i=0;i<states.size();++i){
            if ( memoo[states[i].b1][states[i].b2][states[i].b3]) continue;
            Q.push(states[i]);
        }
    }

    if ( res.size()){
        for (set<int> :: iterator it = res.begin(); it != res.end();++it){
            printf ("%s%d", it == res.begin() ? "" : " ", *it);
        }
    }
    printf ("\n");

    return 0;
}
