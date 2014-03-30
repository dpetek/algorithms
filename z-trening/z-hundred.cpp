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

class Comparator{
public:
    int absCmp(const string &s1, const string &s2) const{
        if ( s1.size() < s2.size()) return -1;
        if ( s2.size() < s1.size()) return 1;
        if ( s1 == s2 ) return 0;
        if ( s1 < s2 ) return -1;
        return 1;
    }

    bool operator ()(const string &s1, const string &s2) const{
        if ( s1[0] == '-' && s2[0] != '-') return true;
        if ( s1[0] != '-' && s2[0] == '-') return false;

        if ( s1[0] != '-' && s2[0] != '-'){
            int cmp = absCmp(s1, s2);
            if ( cmp < 0 ) return true;
            return false;
        }else{
            string ss1 = s1.substr(1);
            string ss2 = s2.substr(1);
            int cmp = absCmp(ss1, ss2);
            if ( cmp > 0 ) return true;
            return false;
        }
    }

};

set<string, Comparator> nums;

int main(void){

    int n , m;
    string s;

    cin >> n >> m;

    for (int i=0;i<n;++i){
        cin >> s;
        nums.insert(s);
    }

    vector<string> v(nums.begin(), nums.end());
    printf ("%s\n", v[m-1].c_str());

    return 0;
}
