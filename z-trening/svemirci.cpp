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

double with[2010];
double without[2010];
bool memoo[2010];
int n;

class Alien{
    public:
        double value;
        int index, enemy;
        Alien(double v, int i, int e) : value(v), index(i), enemy(e){}
};

vector<Alien> aliens;

bool cmp(const Alien &a1, const Alien &a2){
    return with[a1.index] - without[a1.index] > with[a2.index] - without[a2.index];
}

int main(void){
    double v;
    int e;

    scanf("%d", &n);

    for (int i=1;i<=n;++i){
        char tmp[20];
        scanf("%s %d", &tmp, &e);
        for (int j=0;j<strlen(tmp);++j) if (tmp[j] == ',') tmp[j] = '.';
        sscanf(tmp, "%lf", &v);
        aliens.pb(Alien(v, i, e));
        with[i] = without[i] = 0.0;
    }

    for (int i=0;i<aliens.size();++i){
        for (int j=0;j<aliens.size();++j){

            if ( aliens[j].enemy != aliens[i].index){
                with[aliens[i].index] += aliens[j].value;
            }
            if ( i != j ) without[aliens[i].index] += aliens[j].value;
        }
        with[aliens[i].index]+=aliens[i].value;
    }
    sort(aliens.begin(), aliens.end(), cmp);
    double sum = 0.0;

    for (int i=0;i<aliens.size();++i){
        if ( memoo[aliens[i].index] ) continue;
        sum+=aliens[i].value;
        memoo[aliens[i].enemy] = true;
        for (int j=0;j<aliens.size();++j){
            if ( aliens[j].enemy == aliens[i].index){
                memoo[aliens[j].index] = true;
            }
        }
    }
    printf ("%.3lf\n", sum);

    return 0;
}

