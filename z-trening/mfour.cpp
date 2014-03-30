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

int pos[600000];
char s[10005];

int main(void){

    fgets(s, 10002, stdin);
    int i = 4, value = (s[0]-'a')+
                       (s[1]-'a')*26+
                       (s[2]-'a')*26*26+
                       (s[3]-'a')*26*26*26;
    pos[value] = 1;

    while ( s[i] != '\n'){
        value-=(s[i-4]-'a');
        value/=26;
        value+=(s[i]-'a') * 26 * 26 * 26;
        if ( !pos[value] )
            pos[value] = i - 2;
        ++i;
    }

    int n;
    scanf("%d", &n);
    char word[10];
    for (int i=0;i<n;++i){
        scanf("%s", word);
        int encoded = (word[0]-'a')+
                      (word[1]-'a')*26+
                      (word[2]-'a')*26*26+
                      (word[3]-'a')*26*26*26;
        printf("%d\n", pos[encoded]);
    }


    return 0;
}
