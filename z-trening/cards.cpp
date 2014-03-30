#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>

#define pb push_back
#define fs first
#define sc second

using namespace std;

vector <pair<int,int> > numsAsc;
vector <pair<int,int> > numsDesc;
int used[100005];

int main(void){
    int n, a, b;

    scanf ("%d", &n);

    for (int i=0;i<n;++i){
        scanf ("%d %d", &a, &b);
        numsAsc.pb(make_pair(a,i));
        numsAsc.pb(make_pair(b,i));
        numsDesc.pb(make_pair(a,i));
        numsDesc.pb(make_pair(b,i));
    }

    sort (numsAsc.begin(), numsAsc.end());
    sort(numsDesc.begin(), numsDesc.end(), greater<pair<int,int> >());

    int ascIndex = 0, descIndex =0, res =0;

    for (int i=0;i<n/2;++i){
        while ( used[numsAsc[ascIndex].sc] ) ++ascIndex;
        res+=numsAsc[ascIndex].fs;
        printf ("Adding %d\n", numsAsc[ascIndex].fs);
        used[numsAsc[ascIndex].sc] = 1;

        while ( used[numsDesc[descIndex].sc] ) ++descIndex;
        res-=numsDesc[descIndex].fs;
        printf ("Substracting %d\n", numsDesc[descIndex].fs);
        used[numsDesc[descIndex].sc] = 1;
    }

    printf ("%d\n", res);
    return 0;
}
