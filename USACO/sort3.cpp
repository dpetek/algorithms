/*
ID: dpetek11
LANG: C++
TASK: sort3
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

int num1 = 0, num2 = 0, num3 = 0, n;
int v[1003];

int main(void){
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);

    scanf("%d", &n);

    for (int i=0;i<n;++i){
        scanf("%d", &v[i]);
        num1+=(v[i]==1);
        num2+=(v[i]==2);
        num3+=(v[i]==3);
    }
    int cnt = 0;

    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if ( v[i] == 1 && v[j] == 2 && i>=num1 && i <num1+num2 && j < num1){
                v[i] =2;v[j]=1;++cnt;
            }

            if ( v[i] == 1 && v[j] == 3 && i>=num1 +num2 && j < num1){
                v[i] =3;v[j]=1;++cnt;
            }

            if ( v[i] == 3 && v[j] == 2 && i>=num1 && i<num1+num2 && j >= num1+num2){
                v[i] =2;v[j]=3;++cnt;
            }
        }
    }

    for (int i=0;i<num1;++i) if ( v[i] != 1) cnt+=2;

    printf ("%d\n", cnt);

    return 0;
}
