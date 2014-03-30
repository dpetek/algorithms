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

vector<int> dp1;
vector<int> dp2;
vector<int> figures;

int main(void){
    int s, n, k, tmp;

    scanf("%d %d %d", &s, &n, &k);


    for (int i=0;i<n;++i){
        scanf("%d", &tmp);
        figures.push_back(tmp);
    }

    vector<int> dp2(s+1, 0);
    vector<int> dp1(s+1, 0);

    dp2[0] = 1;


    for (int i=0;i<k;++i){
        dp1 = vector<int>(dp2);

        for (int j=0;j<figures.size();++j){
            for (int m=0;m<=s;++m){
                if ( m + figures[j] <= s)
                    dp2[m+figures[j]] += dp2[m];
            }
        }

    }
    int sum = 0;
    for (int i=s;

	return 0;
}
