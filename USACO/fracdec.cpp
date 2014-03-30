/*
ID: dpetek11
LANG: C++
TASK: fracdec
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

string fraction;
string res;
char buff[20];
string miny;

vector<int> connection[100];

int main(void){
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    int n, d;

    scanf("%d %d", &n, &d);
    sprintf(buff, "%d.", n/d);

    n%=d;
    bool exact = false;
    for (int i=0;i<80000;++i){
        int tmp = 0;

        fraction.pb( ((n*10)/d) + '0');
        n = (n*10)%d;
        if ( fraction.size() >= 2 ){
            int tmp = (fraction[fraction.size() - 2]-'0') * 10 + fraction[fraction.size()-1] -'0';
            connection[tmp].pb(fraction.size()-2);
        }
        if ( !n ) {exact = true;break;}
    }

    res = (string)buff;
    if ( exact ){
        printf("%s%s\n", res.c_str(), fraction.c_str());
    }else{
        bool found = false;
        for (int i=0;i<fraction.size();++i){
            if ( miny.size() && i > miny.size()) break;
            int ch = (fraction[i]-'0')*10 + fraction[i+1]-'0';

            for (int j=0;j<connection[ch].size();++j){
                if ( connection[ch][j] >= i ) break;
                bool ok = true;
                for (int t=0;t+i<fraction.size();++t){
                    if ( fraction[i+t] != fraction[connection[ch][j]+t]){
                        ok = false;
                        break;
                    }
                }
                if ( ok ){
                    string s = fraction.substr(0,connection[ch][j]) + "(" + fraction.substr(connection[ch][j], i-connection[ch][j]) + ")";
                    if ( s.size() < miny.size() || miny.size()==0) miny = s;
                    found = true;
                    break;
                }
                if ( found )break;
            }
            if ( found )break;
        }
    }
    res+=miny;
    if (!exact ){
        for (int i=0;i<res.size();++i){
            printf("%c", res[i]);
            if ( i && (i+1) % 76 == 0) printf("\n");
        }
    }
    if (!exact && res.size() % 76 != 0 ) printf ("\n");

    return 0;
}
