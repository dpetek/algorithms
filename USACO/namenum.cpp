/*
ID: dpetek11
LANG: C++
TASK: namenum
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

vector<int> buttons[10];
string word;
vector<string> dict[700];
vector<string> found;

int encode(string s){
    return (s[0]-'A') * 26 + (s[1] - 'A');
}

void addToDict(string s){
    dict[encode(s.substr(0,2))].pb(s);
}

bool goodPrefix(string s){
    if ( s.size() < 2 ) return true;
    int n = encode(s.substr(0, 2));

    for (int i=0;i<dict[n].size();++i){
        if ( s.size() > dict[n][i].size()) continue;
        if ( dict[n][i].substr(0, s.size()) == s) return true;
    }
    return false;
}

bool exists(string s){
    int n = encode(s.substr(0, 2));

    for (int i=0;i<dict[n].size();++i){
        if ( s == dict[n][i] ) return true;
    }
    return false;
}

void rec(string s){
    if ( s.size() == word.size()){

        if ( exists(s) ) found.pb(s);
        return ;
    }

    if ( !goodPrefix(s) ) return ;
    int m = s.size();
    for (int i=0;i<buttons[word[m]-'0'].size();++i){
        s.pb(buttons[word[m]-'0'][i]);
        rec(s);
        s.erase(s.begin() + s.size()-1);
    }
    return ;
}

int main(void){
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);

    buttons[2].pb('A');buttons[2].pb('B');buttons[2].pb('C');
    buttons[3].pb('D');buttons[3].pb('E');buttons[3].pb('F');
    buttons[4].pb('G');buttons[4].pb('H');buttons[4].pb('I');
    buttons[5].pb('J');buttons[5].pb('K');buttons[5].pb('L');
    buttons[6].pb('M');buttons[6].pb('N');buttons[6].pb('O');
    buttons[7].pb('P');buttons[7].pb('R');buttons[7].pb('S');
    buttons[8].pb('T');buttons[8].pb('U');buttons[8].pb('V');
    buttons[9].pb('W');buttons[9].pb('X');buttons[9].pb('Y');

    cin >> word;

    FILE *fin = fopen("dict.txt", "r");
    char buf[30];
    while ( fscanf(fin, "%s", buf) == 1){
        addToDict(buf);
    }

    rec("");

    if ( found.size()) {
        for (int i=0;i<found.size();++i){
            printf ("%s\n", found[i].c_str());
        }
    }else{
        printf ("NONE\n");
    }

    fclose(fin);
    return 0;
}
