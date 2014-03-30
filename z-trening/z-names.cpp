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

const int MAX = 10005;

map<string,int> sortedIndex;
vector<string> names;
vector<string> org;
string tmp;
int cnt[MAX+5];


void update(int num){

    while ( num < MAX){
        cnt[num]++;
        num+=num&(-num);
    }

}

int get(int num){
    int sum = 0;
    while(num > 0){
        sum+=cnt[num];
        num-=num&(-num);
    }
    return sum;
}

int main(void){
    int n;
    scanf("%d", &n);

    for (int i=0;i<n;++i){
        cin >> tmp;
        names.pb(tmp);
        org.pb(tmp);
    }

    sort(names.begin(), names.end());
    for (int i=0;i<n;++i){
        sortedIndex[names[i]] = i+1;
    }

    for (int i=0;i<n;++i){
        int ind = sortedIndex[org[i]];
        int num = get(ind);
        printf ("%d %d\n", num, i-num);
        update(ind);
    }

    return 0;
}
