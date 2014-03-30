/*
ID: dpetek11
LANG: C++
TASK: preface
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

string toRoman(int n){
    string ret ="";

    while ( n >= 1000 ){
        ret += "M";
        n-=1000;
    }
    if (n >= 900 ){ret+="CM";n-=900;}

    if ( n >= 500 ){ ret+="D";n-=500;}
    if ( n >= 400 ){ret+="CD";n-=400;}


    while ( n >= 100){
        ret+="C";
        n-=100;
    }
    if (n >= 90 ){ret+="XC";n-=90;}

    if ( n >= 50 ){ret += "L";n-=50;}
    if ( n >= 40 ){ret += "XL";n-=40;}


    while (n>=10){
        ret+="X";
        n-=10;
    }
    if (n >= 9 ){ret+="IX";n-=9;}
    if ( n >= 5 ) {ret +="V";n-=5;}
    if ( n >= 4 ) {ret += "IV";n-=4;}

    while(n){
        ret+="I";
        n--;
    }
    return ret;
}

int cnt[26];

int main(void){
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);

    int n;

    scanf("%d", &n);

    string digits = "IVXLCDM";

    for (int i=1;i<=n;++i){
        string s = toRoman(i);
        for (int j=0;j<s.size();++j) ++cnt[s[j]-'A'];
    }

    for (int i=0;i<digits.size();++i){
        if ( cnt[digits[i]-'A'] == 0 ) break;
        printf ("%c %d\n", digits[i], cnt[digits[i]-'A']);
    }

    return 0;
}
