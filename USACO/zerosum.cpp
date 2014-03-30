/*
ID: dpetek11
LANG: C++
TASK: zerosum
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
#include <cassert>
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

int n;
int values[10];
int op[10];

vector<string> sol;

bool isValid(){
    vector<int> ops;
    vector<int> v;
    int buf = values[0];


    for (int i=0;i+1<n;++i){
        if ( op[i] == 3){
            buf = buf*10 + values[i+1];
        }else{
             v.pb(buf);
             ops.pb(op[i]);
             buf = values[i+1];
        }
    }
    v.pb(buf);

    int tmp = v[0];

    for (int i=0;i<ops.size();++i){
        if ( ops[i] == 1){
            tmp += v[i+1];
        }else{
            tmp -= v[i+1];
        }
    }
    return tmp == 0;
}

void findSol(int pos){
    if ( pos + 1 == n ){
        if ( isValid() ){
            char res[30];
            sprintf (res, "%d", values[0]);
            for (int i=0;i+1<n;++i){
                char oper;
                if ( op[i] == 1) oper = '+';
                if ( op[i] == 2 ) oper = '-';
                if ( op[i] == 3 ) oper = ' ';
                sprintf (res, "%s%c%d",res, oper, values[i+1]);
            }
            sol.pb(res);
        }
        return ;
    }

    for (int i=1;i<=3;++i){
        op[pos] = i;
        findSol(pos + 1);
    }
}

int main(void){
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    scanf("%d", &n);
    for (int i=0;i<n;++i) values[i] = i + 1;
    findSol(0);

    sort(sol.begin(), sol.end());

    for (int i=0;i<sol.size();++i) printf ("%s\n", sol[i].c_str());
    return 0;
}
