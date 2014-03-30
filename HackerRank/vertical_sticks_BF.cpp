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

double fact(int n){
    if ( n == 0 ) return 1.0;
    if ( n == 1.0 ) return 1.0;
    return 1.0 * n * fact(n-1);
}

int dp[50][50][50];

int main(void){
	int n, a;
	vector<int> nums;
	scanf ("%d", &n);
	for(int i=0;i<n;++i){
        scanf("%d", &a);
        nums.pb(a);
	}

	sort(nums.begin(), nums.end());
    double sum = 0.0;
	do{
        for (int i=0;i<n;++i){
            int cnt = 1;
            for (int j=i-1;j>=0;--j){
                if ( nums[j] >= nums[i] ) break;
                ++cnt;
            }
            sum+=(double)cnt;
            ++dp[nums[i]-1][i+1][cnt];
        }
	}while(next_permutation(nums.begin(), nums.end()));

    for (int i=0;i<30;++i){
        for (int j=0;j<30;++j){
            for (int k=0;k<30;++k){
                if ( dp[i][j][k] != 0 ) printf ("dp[%d][%d][%d]=%d\n", i, j, k, dp[i][j][k]);
            }
        }
    }

    printf ("%.2lf\n", sum/fact(n));
	return 0;
}
