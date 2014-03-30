#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <cmath>
#include <ctime>
#include <cstdlib>
#define pb push_back
#define fs first
#define sc second

using namespace std;

map<string, int> memoo;

int flag[101][101][101];

class Triple{
    public:
        int a,b,c;
        Triple(): a(0), b(0), c(0){}
        Triple(int _a, int _b, int _c) : a(_a), b(_b), c(_c){}
};

char getChar(char a, char b){
    if ( a > b ) return getChar(b,a);
    if ( a == 'a' && b == 'b') return 'c';
    if ( a == 'a' && b == 'c') return 'b';
    if ( a == 'b' && b == 'c') return 'a';
}

int calcOld(string s){
    int &ref = memoo[s];

    if ( s.size() == 1 ) return ref = 1;
    if ( ref != 0 ) return ref;
    int miny = s.size();
    for (int i=1;i<s.size();++i){
        if ( s[i] != s[i-1]){
            miny = min(miny, calcOld(s.substr(0, i-1) + getChar(s[i-1], s[i]) + s.substr(i+1)));
        }
    }
    return ref = miny;
}


bool popEnd(string &s){
    if ( s.size() <= 1 ) return false;
    if ( s[s.size()-1] == s[s.size()-2] ) return false;
    char a = s[s.size()-1];
    char b = s[s.size()-2];
    s.erase(s.end() - 1);
    s.erase(s.end() - 1);
    s.push_back(getChar(a, b));
    return true;
}


bool popStart(string &s){
    if ( s.size() <= 1 ) return false;
    if ( s[0] == s[1] ) return false;
    char a = s[0];
    char b = s[1];
    s.erase(s.begin());
    s.erase(s.begin());
    s = string (1, getChar(a,b)) + s;
    return true;
}

int calc(string s){
    while(popEnd(s) || popStart(s));

    return s.size();
}

int tmpCalc(int a,int b, bool output=false){
    while ( a > 1 || b > 1){
        if ( a == 0 || b == 0 ) break;
        if ( a > b ){
            a-=2;
        }else{
            b-=2;
        }
        if ( a == 0 || b == 0 ) break;
    }
    if ( a == 0) return b;
    if ( b == 0) return a;
    return -1;
}

int calcReduction(int together, int other){

    if ( together == -1) return other + 1;
    return abs(tmpCalc(together, other));
}

int calc3(string s, int tc){
    queue<Triple> Q;
    int cnta = 0, cntb = 0, cntc = 0;
    for (int i=0;i<s.size();++i){
        cnta += s[i] == 'a';
        cntb += s[i] == 'b';
        cntc += s[i] == 'c';
    }

//    int ab = tmpCalc(cnta, cntb, true);
//    int bc = tmpCalc(cntb, cntc);
//    int ac = tmpCalc(cnta, cntc);
//    int miny = 200;
//    // a-b-c
//    miny = min(miny, calcReduction(ab,cntc));
//    miny = min(miny, calcReduction(ac,cntb));
//    miny = min(miny, calcReduction(bc,cnta));
//    miny = min(miny, calcReduction(ab,cntc));
//    miny = min(miny, calcReduction(ac,cntb));
//    miny = min(miny, calcReduction(bc,cnta));

    Q.push(Triple(cnta, cntb, cntc));
    int miny = 9999999;
    while (!Q.empty()){
        int a = Q.front().a;
        int b = Q.front().b;
        int c = Q.front().c;
        Q.pop();
        miny = min(miny, a + b + c);
        if ( flag[a][b][c] == tc ) continue;
        flag[a][b][c] = tc;

        if ( a > 1 && (b || c)) Q.push(Triple(a-2, b, c));
        if ( b > 1 && (a || c)) Q.push(Triple(a,b-2, c));
        if ( c > 1 && (a || b)) Q.push(Triple(a,b, c-2));

        if ( a == 1 && b == 1) Q.push(Triple(0,0, c + 1));
        if ( a == 1 && c == 1) Q.push(Triple(0, b+1, 0));
        if ( b == 1 && c == 1) Q.push(Triple(a+1, 0, 0));

    }


    return miny;
}

string getRandomString(){
//    return "ababcacacba";
    srand(time(0));
    int n = rand() % 5 + 7;

    string s;
    for (int i=0;i<n;++i){
        int r = rand() % 3;
        if ( r == 0 ) s.push_back('a');
        if ( r == 1 ) s.push_back('b');
        if ( r == 2 ) s.push_back('c');
    }
    return s;
}

int main(void){
    int _test;

    scanf("%d", &_test);
    string tmp;
    for (int t=0;t<_test;++t){
        cin >> tmp;
        printf ("%d\n", calc3(tmp, t + 1));
    }

//    for (int i=0;i<1;++i){
//        string s = getRandomString();
//        int c1 = calcOld(s);
//        int c2 = calc3(s, i+1);
//        if ( c1 != c2) {
//            printf ("%s %d %d\n", s.c_str(), c1, c2);
//            break;
//        }
//    }

	return 0;
}
