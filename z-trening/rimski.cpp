#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#define pb push_back
#define fs first
#define sc second

using namespace std;

string tens[] = {
    "",
    "X",
    "XX",
    "XXX",
    "XL",
    "L",
    "LX",
    "LXX",
    "LXXX",
    "XC"
};
string ones[] = {
    "",
    "I",
    "II",
    "III",
    "IV",
    "V",
    "VI",
    "VII",
    "VIII",
    "IX",
};

string toRoman(int n){
    return tens[n/10] + ones[n%10];
}

int main(void){
    string s;

    cin >> s;
    sort(s.begin(), s.end());
    for (int i=1;i<100;++i){
        string r = toRoman(i);
        string rr = r;
        sort(rr.begin(), rr.end());
        if ( rr == s ){
            cout << r << endl;
            break;
        }

    }

	return 0;
}
