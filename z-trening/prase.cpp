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

map<string,int> cnt;
char buffer[22];

int main(void){
    int n;

    scanf("%d", &n);
    int num = 0;
    for (int i=0;i<n;++i){
        scanf("%s", buffer);
        int c = cnt[buffer];
        if ( c >= i + 1 - c) ++ num;
        ++cnt[buffer];
    }

        printf ("%d\n", num);
	return 0;
}
