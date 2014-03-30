#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#define pb push_back
#define fs first
#define sc second

using namespace std;

vector<int> numbers;


int main(void){
    int K, n, a;

    scanf("%d %d", &n, &K);

    for (int i=0;i<n;++i){
        scanf("%d", &a);
        numbers.push_back(a);
    }
    int cnt = 0;
    sort(numbers.begin(), numbers.end());

    for(vector<int> :: iterator it=numbers.begin();it != numbers.end();++it){
        vector<int> :: iterator lb = lower_bound(numbers.begin(), numbers.end(), *it + K);

        while(lb != numbers.end() && *lb == (*it + K)) {++cnt;++lb;}
    }
    printf ("%d\n", cnt);


	return 0;
}
