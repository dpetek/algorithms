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


int _d[11][11];

string buttons[4] = {
    "123",
    "456",
    "789",
    "x0x"
};

int dist(int a, int b){
    if ( _d[a][b] ) return _d[a][b];
    if ( _d[b][a] ) return _d[b][a];

    int xa, ya, xb, yb;
    for (int i=0;i<4;++i){
        for (int j=0;j<buttons[i].size();++j){
            if ( buttons[i][j] - '0' == a){
                xa = i;ya = j;
            }
            if ( buttons[i][j] - '0' == b){
                xb = i;yb = j;
            }
        }
    }
    return _d[a][b] = _d[b][a] = abs(xa - xb) + abs(ya - yb);
}

int main(void){

    string num;
    int sum = 0;
    cin >> num;

    int curr = 5;

    for (int i=0;i<num.size();++i){
        sum+=dist(curr, num[i] - '0');
        curr = num[i] - '0';
    }

    cout << sum << endl;
	return 0;
}
