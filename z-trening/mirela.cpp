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


int main(void){
	int n, sum = 1;

	cin >> n;
	for (int i=0;i<n;++i){
        sum+=6*i;
	}

	cout << sum << endl;
	return 0;
}
