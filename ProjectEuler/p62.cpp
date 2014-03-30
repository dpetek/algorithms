#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

map<string, vector<long long> > cnt;

string ll2str(long long n){
    char buffer[30];
    sprintf (buffer, "%lld", n);
    return buffer;
}

long long str2ll(string s){
    long long ret;
    sscanf(s.c_str(), "%lld", &ret);
    return ret;
}


bool isCube(long long n){
    long long m = (long long)pow(1.0 * n , 1.0 / 3.0);

    if ( m * m * m == n ) return true;
    return false;
}
int main(void){


    for (long long i=1LL;i<10000LL;++i){
        string s = ll2str(i*i*i);
        sort(s.begin(), s.end());
        cnt[s].push_back(i);
    }

    long long miny = -1LL;
    for (map<string,vector<long long> >:: iterator it = cnt.begin();it != cnt.end();++it){
        if ( it->second.size() == 5 ){
            long long m = it->second[0];
            if ( miny == -1LL || m*m*m < miny){
                printf ("\t%lld\n", m);
                miny = m * m * m;
            }
        }
    }

    printf ("%lld\n", miny);
    return 0;
}
