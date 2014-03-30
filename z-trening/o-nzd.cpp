#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <cctype>
#define pb push_back
#define fs first
#define sc second

using namespace std;

unsigned long long decodeH(char c){
    if ( c >= '0' && c <= '9') return (unsigned long long)(c-'0');
    c = tolower(c);
    return (unsigned long long)(c-'a' + 10);
}

unsigned long long h2d(string h){
    unsigned long long ret = 0ULL, pot = 1ULL;

    for (int i=h.size()-1;i>=0;--i){
        ret+=pot * decodeH(h[i]);
        pot*=16ULL;
    }
    return ret;
}

unsigned long long b2d(string b){
    unsigned long long ret = 0ULL, pot=1ULL;
    for (int i=b.size()-1;i>=0;--i){
        if ( b[i] == '1') ret+=pot;
        pot*=2ULL;
    }
    return ret;
}

unsigned long long gcd(unsigned long long a, unsigned long long b){
    if ( b == 0ULL) return a;
    return gcd(b, a%b);
}

int main(void){
	string h, b;

	cin >> h >> b;
    cout << gcd(h2d(h), b2d(b)) << endl;
	return 0;
}
