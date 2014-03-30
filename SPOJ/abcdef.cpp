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
#include <cassert>
#include <cmath>
#define pb push_back
#define fs first
#define sc second
#define foreach(c,it) for(typeof(((c).begin())) it=((c).begin());(it)!=((c).end());++(it))
#define _sz(c) ((int)c.size())
#define cstr(s) ((s).c_str())
using namespace std;
vector<int> s;


#define MOD 1000003

vector<pair<int,int> > hash[MOD + 5];

map<int,int> leftCnt;
map<int,int> rightCnt;

inline int my_mod(int a){
    int r = a % MOD;
    if ( r < 0 ) return (r+MOD)%MOD;
    return r;
}

void addNum(int &num){
    int h = my_mod(num);
    assert(h>=0 && h < MOD);
    bool found = false;
    for(int i=0;i<hash[h].size();++i){
        if ( hash[h][i].fs == num ){
            ++hash[h][i].sc;
            found = true;
            break;
        }
    }
    if ( !found )hash[h].push_back(make_pair(num,1));
}

int gotNum(int &num){
    int h = my_mod(num);
    assert(h>=0 && h < MOD);
    for(int i=0;i<hash[h].size();++i){
        if ( hash[h][i].fs == num ){
            return hash[h][i].sc;
        }
    }
    return 0;
}

int main(void){
    int n,a;

    scanf ("%d", &n);

    for (int i=0;i<n;++i){
        scanf("%d", &a);
        s.pb(a);
    }
    for (int a=0;a<s.size();++a){
        for (int b=0;b<s.size();++b){
            for (int c=0;c<s.size();++c){
                int tmp = s[a] * s[b] + s[c];
                int tmp2 = (s[a] + s[b]) * s[c];
                addNum(tmp);
            }
        }
    }
    long long ret = 0;

    for (int a=0;a<s.size();++a){
        for (int b=0;b<s.size();++b){
            for (int c=0;c<s.size();++c){
                int tmp2 = (s[a] + s[b]) * s[c];
                int left = gotNum(tmp2);
                ret+=(long long)left;
            }
        }
    }
    printf ("%lld\n", ret);
    return 0;
}


