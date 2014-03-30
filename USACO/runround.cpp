/*
ID: dpetek11
LANG: C++
TASK: runround
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

bool isRun(string  snum){
    bool used[12] = {0};
    int cnt = 0, pos = 0;

    int n = snum.size();

    while ( !used[pos] ){
        used[pos] = true;
        ++cnt;
        pos = (pos + (snum[pos]-'0')) % n;
    }
    return cnt == n && pos == 0;
}

int main(void){
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);

    string s;
    int n;

    cin >> s;
    sscanf(s.c_str(), "%d", &n);

    string num = "123456789", ms = "999999999";
    int cnt = 0, miny = 1e8;

    do{
        for (int i=s.size();i<=ms.size();++i){
            string sub = num.substr(0,i);

            if ( isRun(sub)) {
                int tmp;
                sscanf(sub.c_str(), "%d", &tmp);
                if ( tmp - n > 0 ){
                    ms = sub;
                    if ( tmp - n < miny){
                        miny = tmp-n;
                    }
                }

            }
        }
    }while(next_permutation(num.begin(), num.end()));
    printf ("%d\n", n + miny);
    return 0;
}
