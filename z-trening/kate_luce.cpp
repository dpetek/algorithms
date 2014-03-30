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

	int n;

	cin >> n;
	int miny = -1;
	for (int i=1;i<=n;++i){
        if ( n % i != 0 ) continue;
        if ( miny == -1 || 2 * i + 2 * ( n / i )  < miny ) miny = 2 * i + 2 * (n / i);

	}


    cout << miny << endl;
	return 0;
}
