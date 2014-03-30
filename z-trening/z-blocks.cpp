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

const int MAX = 20010;
int cnt[MAX+10];

void update(int n, int num){
    while (n <= MAX){
        cnt[n]+=num;
        n+=n&(-n);
    }
}

int get(int n){
    if ( !n ) return 0;
    int sum = 0;
    while (n > 0){
        sum+=cnt[n];
        n-=n&(-n);

    }
    return sum;
}
char s[MAX], command[5];

int main(void){
    int n, q, a, b, c;
    scanf("%d %d\n", &n, &q);

    fgets(s, MAX, stdin);
    s[n] = '\0';

    for (int i=0;i<n;++i){
        if ( s[i] == 'B' ) update(i+1, 1);
    }

    for (int i=0;i<q;++i){
        scanf("%s", command);
        if ( command[0] == 'C'){
            scanf("%d %d", &a, &b);
            printf("%d\n",  get(b)-get(a-1));
        }else{
            scanf("%d %d %d", &a, &b, &c);
            for (int j=0;j<c;++j){
                if ( s[a+j-1] == 'B' && s[b+j-1] == 'W'){
                    s[a+j-1] = 'W';
                    s[b+j-1] = 'B';
                    update(a+j,-1);
                    update(b+j,1);
                }else if (s[a+j-1]=='W' && s[b+j-1] == 'B'){
                    s[a+j-1] = 'B';
                    s[b+j-1] = 'W';
                    update(a+j,1);
                    update(b+j,-1);
                }
            }
        }
    }
    return 0;
}
