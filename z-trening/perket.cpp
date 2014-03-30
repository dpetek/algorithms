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

vector<pair<long long,long long> > v;


int main(void){
    int a, b, n;

    cin >> n;
    for (int i=0;i<n;++i){
        cin >> a >> b;
        v.pb(make_pair((long long)a,(long long)b));
    }

    long long minyDiff = -1LL;

    for (int mask=1;mask < 1<<v.size();++mask){
        long long s = 1LL, b = 0LL;

        for (int i=0;i<v.size();++i){
            if ( mask & ( 1 << i) ){
                b+=v[i].sc;
                s*=v[i].fs;

            }
        }
        if (minyDiff == -1 ) minyDiff = abs(s-b);
        else minyDiff = min(minyDiff, abs(s-b));
    }

    cout << minyDiff << endl;

	return 0;
}
