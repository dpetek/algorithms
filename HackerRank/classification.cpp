//kNN algorithm

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <list>
#include <set>
#define pb push_back
#define fs first
#define sc second

using namespace std;

class Feature{
    public:
        vector<double> value;
        string name;
        int featureClass;

        Feature(string _name, int fc, int m) : name(_name), featureClass(fc){
            value = vector<double>(m, 0.0);
        }

        void addValue(int index, double v){
            value[index-1] = v;
        }

        void scaleValue(int i, double miny, double maxy){
            if ( abs(maxy - miny) > 1e-7)
                value[i] = (value[i] - miny) / (maxy - miny);
        }

        void scale(vector<double> &miny, vector<double> &maxy){
            for (int i=0;i<miny.size();++i) scaleValue(i, miny[i], maxy[i]);
        }

};

vector<Feature> testSet;

double calcDist(Feature &f1, Feature &f2){

    int m = f1.value.size();
    double sqsum = 0.0;
    for (int i=0;i<m;++i){
        sqsum+= (f1.value[i] - f2.value[i]) * (f1.value[i] - f2.value[i]);
    }
    return sqsum;
}

int getKNNResult(Feature &f){
    set<pair<double, int> > best;
    int N = 3;

    for (int i=0;i<testSet.size();++i){
        double d = calcDist(f, testSet[i]);
        if ( best.size() < N ){
            best.insert(make_pair(d, testSet[i].featureClass));
        }else{
            set<pair<double, int> > :: iterator it = best.begin();
            for (int j=0;j+1<N;++j) ++it;
            if ( it->first > d){
                best.erase(it);
                best.insert(make_pair(d, testSet[i].featureClass));

            }
        }
    }
    int cntPlus = 0, cntMinus = 0;
    for(set<pair<double, int> > :: iterator it = best.begin();it != best.end();++it){
        if ( it->second == 1 ) ++cntPlus;
        else ++cntMinus;
    }
    return (cntPlus > cntMinus) ? 1 : -1;
}


char tmpName[100];
int main(void){
    int n, m, tmpClass;
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);
    scanf ("%d %d", &n, &m);

    vector<double> scaleMiny;
    vector<double> scaleMaxy;

    for (int i=0;i<n;++i){
        scanf("%s", tmpName);

        scanf("%d", &tmpClass);
        Feature f(tmpName, tmpClass, m);
        char c;
        string tmp = "";
        int index;
        double v;
        for (int j=0;j<m;++j){
            scanf ("%d:%lf", &index, &v);
            f.addValue(index, v);
            if ( scaleMiny.size() <= j) scaleMiny.push_back(v);
            else{
                if ( v < scaleMiny[j] ) scaleMiny[j] = v;
            }
            if ( scaleMaxy.size() <= j) scaleMaxy.push_back(v);
            else{
                if ( v > scaleMaxy[j]) scaleMaxy[j] = v;
            }
        }
        testSet.push_back(f);
    }

    int numData;
//    printf ("%d %d\n", scaleMiny.size(), scaleMaxy.size());fflush(stdout);
    for (int i=0;i<testSet.size();++i){
        testSet[i].scale(scaleMiny, scaleMaxy);
    }

    scanf("%d", &numData);
    for (int i=0;i<numData;++i){
        scanf("%s", tmpName);


        Feature f(tmpName, tmpClass, m);
        char c;
        string tmp = "";
        int index;
        double v;
        for (int j=0;j<m;++j){
            scanf ("%d:%lf", &index, &v);
            f.addValue(index, v);
        }
        f.scale(scaleMiny, scaleMaxy);
        int res = getKNNResult(f);
        printf ("%s %s%d\n",tmpName, res == 1 ? "+" : "", res);
    }


	return 0;
}
