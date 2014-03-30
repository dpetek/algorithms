/*
ID: dpetek11
LANG: C++
TASK: prefix
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

set<string> primitives;
char buffer[80];
string s;
int memoo[200003];


bool check(int pos){
    int &ref = memoo[pos];
    if ( pos == -1) return ref = true;
    if ( ref != -1) return ref;


    for (set<string> :: iterator it = primitives.begin();it != primitives.end();++it){
        if ( it->size() > pos + 1 ) continue;

        bool ok = true;
        for (int i=0;i<it->size();++i){
            if ( (*it)[i] != s[pos-it->size() + 1 + i]) {ok = false;break;}
        }
        if ( ok ){
//            printf ("Pos %d -> matched %s -> going to %d\n", pos, it->c_str(), pos - it->size());
            bool b = check(pos - it->size());
            if ( b ) return ref = true;
        }
    }
    return ref = false;
}

int main(void){
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    for (int i=0;i<200000;++i) memoo[i] = -1;

    while (true){
        scanf("%s", buffer);
        if (buffer[0] == '.') break;
        primitives.insert(buffer);
    }

    while(scanf("%s", buffer)==1){
        s+=buffer;
    }
    bool found = false;
    for (int i=s.size()-1;i>=0;--i){
        if ( check(i) ){
            found = true;
            printf ("%d\n", i + 1);
            break;
        }
    }
    if ( !found ) printf ("%d\n", 0);

    return 0;
}
