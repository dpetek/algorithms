/*
ID: dpetek11
LANG: C++
TASK: transform
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

vector<string> rotate90(vector<string> v){
    vector<string> ret;

    for (int i=0;i<v.size();++i){
        string tmp;
        for (int j=v.size()-1;j>=0;--j){
            tmp+=v[j][i];
        }
        ret.pb(tmp);
    }
    return ret;
}


vector <string> reflect (vector<string> v){

    for (int i=0;i<v.size();++i){
        for (int j=0;j*2<v.size();++j){
            char tmp = v[i][j];
            v[i][j] = v[i][v.size() -j -1];
            v[i][v.size() - j - 1] = tmp;
        }
    }
    return v;
}

int getTransform(vector<string> v1, vector<string> v2){
    vector<string> rot90 = rotate90(v1);
    vector<string> rot180 = rotate90(rot90);
    vector<string> rot270 = rotate90(rot180);

    if ( rot90 == v2 ) return 1;
    if ( rot180 == v2 ) return 2;
    if ( rot270 == v2 ) return 3;

    vector <string> ref = reflect(v1);

    if ( ref == v2 ) return 4;

    vector<string> rrot90 = rotate90(ref);
    vector<string> rrot180 = rotate90(rrot90);
    vector<string> rrot270 = rotate90(rrot180);

    if ( rrot90 == v2 ||
         rrot180 == v2 ||
         rrot270 == v2) return 5;

    if ( v1 == v2 ) return 6;

    return 7;



}

int main(void){
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int n;
    string tmp;

    vector<string> begin, end;

    cin >> n;
    for (int i=0;i<n;++i){
        cin >> tmp;
        begin.pb(tmp);
    }

    for (int i=0;i<n;++i){
        cin >> tmp;
        end.pb(tmp);
    }


    printf ("%d\n", getTransform(begin, end));

    return 0;
}
