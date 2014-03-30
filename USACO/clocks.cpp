/*
ID: dpetek11
LANG: C++
TASK: clocks
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

#define GOAL 262143

int memoo[1<<19];
int action[1<<19];

string move[9]={
    "ABDE",
    "ABC",
    "BCEF",
    "ADG",
    "BDEFH",
    "CFI",
    "DEGH",
    "GHI",
    "EFHI"
};
int encode(vector<int> &v){
    int ret = 0;
    for (int i=0;i<v.size();++i){
        int t = 0x3 & ((v[i] / 3) - 1);
        ret |= (t << (i*2));
    }
    return ret;
}

vector<int> decode(int num){
    vector<int> ret;
    for (int i=0;i<9;++i){
        int t = (num & (0x3 << (i*2))) >> (i*2);
        ret.pb((t+1)*3);
    }
    return ret;
}


int rotate (int n, int cl){
    int t = (n & (0x3 << (cl*2))) >> (cl*2);
    t = (t+1)&0x3;
    int r = (n & (~(0x3 << (cl*2)))) | (t << (cl*2));
    return r;
}


queue<int > Q;

int main(void){
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
    vector<int> v;
    int tmp;
    for (int i=0;i<9;++i){
        scanf("%d", &tmp);
        v.pb(tmp);
    }
    for (int i=0;i<=(1<<19);++i) memoo[i] = -1;
    int start = encode(v);
    Q.push(encode(v));

    while ( !Q.empty() ){
        int clocks = Q.front();
        Q.pop();

        if ( clocks == GOAL){
            break;
        }

        for (int i=0;i<9;++i){
            int num = clocks;
            for (int j=0;j<move[i].size();++j) num = rotate(num, move[i][j]-'A');
            if ( memoo[num] > 0 || num == start) continue;
            memoo[num] = clocks;
            action[num] = i + 1;
            Q.push(num);
        }
    }

    vector<int> path;
    int curr = GOAL;


    while(memoo[curr] != -1){
        path.pb(action[curr]);
        curr = memoo[curr];
    }
    reverse(path.begin(), path.end());

    for (int i=0;i<path.size();++i){
        printf ("%s%d", i ? " " : "", path[i]);
    }
    printf ("\n");

    return 0;
}
