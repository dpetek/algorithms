/*
ID: dpetek11
LANG: C++
TASK: palsquare
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

char toChar(int ch){
    if ( ch <= 9 ) return ch + '0';
    return ch - 10 + 'A';
}

string toBase(int n, int b){
    string s;
    while ( n ){
        s.pb( toChar(n % b) );
        n/=b;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool isPal(string s){
    for (int i=0;i*2<s.size();++i){
        if ( s[i] != s[s.size()-i-1])return false;
    }
    return true;
}

int main(void){
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int b;
    cin >> b;
    for (int i=1;i<=300;++i){
        string s = toBase(i*i, b);
        if ( isPal(s)){
            printf ("%s %s\n",toBase(i,b).c_str(), s.c_str());
        }
    }

    return 0;
}
