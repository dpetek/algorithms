/*
ID: dpetek11
LANG: C++
TASK: msquare
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

char oper[(1<<21) + 1];
int prev[(1<<21)+1];

queue<int> Q;

int encode(vector<int> &v, bool rev = false){
    int ret = 0;
    if ( rev )
        reverse(v.begin() + 4, v.end());
    for (int i=0;i+1<v.size();++i){
        ret = (ret << 3) | (v[i]-1);
    }
    return ret;
}

vector<int> decode(int &n){
    vector<int> ret;
    int sum = 0;
    for (int i=6;i>=0;--i){
        int tmp = (n >> ( i * 3) ) & 0x7;
        sum+=tmp+1;
        ret.pb(tmp+1);
    }
    ret.pb(36 - sum);

    return ret;
}


int transfA(int &n){
    vector<int> num = decode(n);
    rotate(num.begin(), num.begin()+4, num.end());
    return encode(num);
}

int transfB(int &n){
    vector<int> num = decode(n);
    rotate(num.begin(), num.begin() + 3, num.begin() + 4);
    rotate(num.begin() +4, num.begin() + 7, num.end());
    return encode(num);
}

int transfC(int &n){
    vector<int> num = decode(n);
    int tmp = num[5];
    num[5] = num[6];
    num[6] = num[2];
    num[2] = num[1];
    num[1] = tmp;
    return encode(num);
}

void printV(vector<int> v, string pref = ""){
    printf ("%s", pref.c_str());
    for (int i=0;i<v.size();++i) printf ("%d ", v[i]);
    printf ("\n");
}

int main(void){
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);

    vector<int> buffer;
    int tmp;

    for (int i=0;i<8;++i){
        scanf("%d", &tmp);
        buffer.pb(tmp);
    }

    vector<int> _buff;
    for (int i=1;i<=8;++i) _buff.pb(i);
    int goal = encode(buffer, true);

    Q.push(encode(_buff, true));

    for (int i=0;i<=(1<<21);++i) oper[i] = 'x';
    oper[encode(_buff, true)] = 's';

    while (!Q.empty()){
        int num = Q.front();
        Q.pop();
        if ( num == goal ){
             break;
        }

        printV(decode(num));

        int ta = transfA(num);

        if ( oper[ta] == 'x'){
            oper[ta] = 'A';
            prev[ta] = num;
            printV(decode(ta), "\tA: ");
            Q.push(ta);
        }

        int tb = transfB(num);

        if ( oper[tb] == 'x'){
            oper[tb] = 'B';
            prev[tb] = num;
            printV(decode(tb), "\tB: ");
            Q.push(tb);
        }

        int tc = transfC(num);
        if ( oper[tc] == 'x'){
            oper[tc] = 'C';
            prev[tc] = num;
            printV(decode(tc), "\tC: ");
            Q.push(tc);
        }
    }


    return 0;
}
