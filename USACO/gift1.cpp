/*
ID: dpetek11
LANG: C++
TASK: gift1
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

map<string, int> money;
vector<string> names;

int main(void){
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);

    int n, a, b;
    string name, tmp;

    cin >> n;

    for (int i=0;i<n;++i){
        cin >> tmp;
        money[tmp] = 0;
        names.pb(tmp);
    }

    for (int t=0;t<n;++t){
        cin >> name;
        cin >> a >> b;
        if ( !b ) continue;
        int part = a / b;
        money[name]-= (a/b) * b;

        for (int i=0;i<b;++i){
            cin >> tmp;
            money[tmp] += part;
        }
    }

    for (int i=0;i<names.size();++i){
        printf ("%s %d\n", names[i].c_str(), money[names[i]]);
    }

    return 0;
}
