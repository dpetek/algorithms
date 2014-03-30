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

vector<int> bricks;

int main(void){
	int n, a, sum = 0;
	scanf("%d", &n);


    for (int i=0;i<n;++i){
        scanf("%d", &a);
        sum+=a;
        bricks.push_back(a);
    }
    int goal = sum / n;
    int moves = 0;
    for (int i=0;i<n;++i){
        if ( bricks[i] > goal ) moves+=bricks[i]-goal;
    }
    printf ("%d\n", moves);

	return 0;
}
