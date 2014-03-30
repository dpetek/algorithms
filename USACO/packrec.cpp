/*
ID: dpetek11
LANG: C++
TASK: packrec
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
vector<pair<int, int> > rect;
int miny = 1e6;

inline int max2(int a, int b){
    return max(a,b);
}
inline int max3(int a, int b,int c){
    return max(a,max(b,c));
}
inline int max4(int a, int b, int c,int d){
    return max(max(a,b), max(c,d));
}

pair<int, int> norm(pair<int,int> p){
    return make_pair(min(p.fs, p.sc), max(p.fs, p.sc));
}

struct comparator{
    bool operator () (const pair<int,int> &p1, const pair<int, int> &p2){
        if ( p1.fs * p1.sc != p2.fs * p2.sc ) return p1.fs * p1.sc < p2.fs * p2.sc;
        return p1 < p2;
    }
};

set<pair<int, int> , comparator> sol;

void check(int w, int h){
    if ( w * h <= miny){
        miny = w*h;
        sol.insert(norm(make_pair(w,h)));
    }
}

void process(int mask){
    int w1 = (mask & 1) ? rect[0].sc : rect[0].fs;
    int h1 = (mask & 1) ? rect[0].fs : rect[0].sc;
    int w2 = (mask & 2) ? rect[1].sc : rect[1].fs;
    int h2 = (mask & 2) ? rect[1].fs : rect[1].sc;
    int w3 = (mask & 4) ? rect[2].sc : rect[2].fs;
    int h3 = (mask & 4) ? rect[2].fs : rect[2].sc;
    int w4 = (mask & 8) ? rect[3].sc : rect[3].fs;
    int h4 = (mask & 8) ? rect[3].fs : rect[3].sc;

    //layout 1
    int H1 = max(h1, max(h2, max(h3, h4)));
    int W1 = w1 + w2 + w3 + w4;
    check(W1, H1);

    //layout 2
    int H2 = max(h2, max(h3, h4)) + h1;
    int W2 = max(w2+w3+w4, w1);
    check(W2, H2);

    //layout 3
    int H3 = max2( h4, max2( h1,h2) + h3 );
    int W3 = w4 + max2(w1+w2,w3);
    check(W3, H3);

    //layout 4 & 5
    int H4 = max3( h1 + h2 , h3 , h4 );
    int W4 = max(w1,w2) + w3 + w4;

    check(W4, H4);

    //layout 6
    int H6, W6;
    H6=max(h1+h3,h2+h4);
      if (h3>=h2+h4)
         W6=max(w1,w3+max(w2,w4));
      if (h3>h4&&h3<h2+h4)
         W6=max(w1+w2,w3+max(w2,w4));
      if (h3<h4&&h4<h1+h3)
         W6=max(w1+w2,w4+max(w1,w3));
      if (h4>=h1+h3)
         W6=max(w2,w4+max(w1,w3));
      if (h3==h4)
         W6=max(w1+w2,w3+w4);

    check(W6, H6);
}




int main(void){
    freopen("packrec.in", "r", stdin);
    freopen("packrec.out", "w", stdout);
    int w, h;

    for (int i=0;i<4;++i){
        scanf("%d %d", &w, &h);
        rect.pb(make_pair(w,h));
    }

    sort(rect.begin(), rect.end());

    do{

        for (int mask=0;mask<(1<<4);++mask){
            process(mask);
        }
    }while(next_permutation(rect.begin(), rect.end()));
    int optimal = (*sol.begin()).fs * (*sol.begin()).sc;
    printf ("%d\n", optimal);
    for (set<pair<int,int> > :: iterator it = sol.begin();it != sol.end();++it){
        if ( it->fs * it->sc != optimal ) break;
        printf ("%d %d\n", it->fs, it->sc);
    }

    return 0;
}
