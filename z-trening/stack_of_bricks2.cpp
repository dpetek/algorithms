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

    if (n == 0 ){
        printf ("0\n");
        return 0;
    }

    int goal = sum / n;
    int moves = 0;
    for (int i=0;i<n;++i){
        if ( bricks[i] >= goal ) continue;

        int i1 = i;
        int i2 = i;
        while ( i1 >= 0){
            --i1;

            if ( i1 >= 0 && bricks[i1] > goal){
                int diff = bricks[i1] - goal;
                int need = goal - bricks[i];

                if ( diff >= need ){
                    bricks[i1] -= need;
                    bricks[i] += need;
                    moves += (i - i1) * need;

                    break;
                }else{
                    bricks[i1] = goal;
                    bricks[i] += diff;
                    moves += (i-i1) * diff;
                }
            }
        }

        while ( i2 < n ){
            ++i2;

            if ( i2 < n && bricks[i2] > goal){
                int diff = bricks[i2] - goal;
                int need = goal - bricks[i];
                if ( diff >= need ){
                    bricks[i2] -= need;
                    moves += (i2-i) * need;
                    bricks[i] += need;
                    break;
                }else{
                    bricks[i2] = goal;
                    bricks[i] += diff;
                    moves += (i2-i) * diff;
                }
            }

        }
    }
    printf ("%d\n", moves);

	return 0;
}
