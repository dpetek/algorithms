#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define pb push_back
#define fs first
#define sc second
using namespace std;

inline void _swap(int &a, int &b){
    int tmp = a;
    a = b; b = tmp;
}

int main(void){
    vector <int> v;
    int tmp;
    for (int i=0;i<5;++i){
        scanf("%d", &tmp);
        v.pb(tmp);
    }
    bool done = false;
    int ind = 1;
    while ( !done ){
        bool swaped = false;

        if ( v[ind] < v[ind-1] ){
            _swap(v[ind], v[ind-1]);
            for (int i=0;i<5;++i) printf ("%s%d", (!i)?(""):(" "), v[i]);
            printf ("\n");
        }
        ind = (ind+1)%5;
        bool ok  = true;
        for (int i=0;i<5;++i) if ( v[i] != i+1) ok = false;
        if ( ok ) break;
    }

    return 0;
}
