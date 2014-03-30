/*
ID: dpetek11
LANG: C++
TASK: contact
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

int cnt[13][(1<<12)+1];

string to_bin(int num, int dig){
    string ret = "";
    while ( num ){
        ret.pb(num%2 + '0');
        num/=2;
    }
    while(ret.size() < dig) ret.pb('0');
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(void){
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    int a, b, n;

    scanf("%d %d %d",&a, &b, &n);
    int num = 0, buffer=0;
    for(int i=0;;++i){
        char ch = getchar();

        if ( ch == EOF || ch <= 0) break;
        if ( ch != '0' && ch != '1') continue;
        ++num;
        buffer = (buffer << 1) | (ch-'0');

        for (int j=a;j<=b;++j){
            if (num < j) continue;
            ++cnt[j][buffer & ((1<<j)-1)];
        }

    }

    set<pair<pair<int,int>,int>, greater<pair<pair<int,int>,int> > > S;

    for (int i=1;i<=12;++i){
        for (int j=0;j<=(1<<i);++j){
            if ( cnt[i][j] ) S.insert(make_pair(make_pair(cnt[i][j],-i), -j));
        }
    }

    int br = 0, prev = -1,nl = false, line_count = 0;
    for (set<pair<pair<int,int>,int> > :: iterator it = S.begin();it!=S.end();++it){
        if ( it->fs.fs != prev ) {
            if ( br + 1> n ) break;
            printf("%s%d\n", prev == -1 ? "" : "\n" , it->fs.fs);
            nl = true;
            ++br;
            line_count = 0;
        }

        if ( line_count == 6 ) {printf ("\n");nl=true;line_count=0;}
        printf("%s%s", nl ? ("") : (" "), to_bin(-it->sc, -it->fs.sc).c_str());
        nl = false;
        ++line_count;
        prev = it->fs.fs;
    }
    printf ("\n");
    return 0;
}
