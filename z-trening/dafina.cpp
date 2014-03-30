#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cmath>
#define pb push_back
#define fs first
#define sc second
#define foreach(c,it) for(typeof(((c).begin())) it=((c).begin());(it)!=((c).end());++(it))
#define _sz(c) ((int)c.size())
#define cstr(s) ((s).c_str())
using namespace std;


class BigNum{
    private:
        vector<int> num;
        static const int BASE = 1000000;

        BigNum(vector<int> v){
            this->num = v;
        }

    public:
        BigNum(){}

        BigNum(int n){
            num.clear();
            while(n){
                num.push_back(n%BASE);
                n/=BASE;
            }
        }

        string toString(){
            if ( !num.size() ) return string("0");
            char buffer[400]={0};
            for (int i=num.size()-1;i>=0;--i){
                if ( i == num.size()-1) sprintf (buffer, "%s%d",buffer, num[i]);
                else sprintf (buffer, "%s%06d", buffer, num[i]);
            }
            return buffer;
        }

        BigNum operator +(const BigNum &b){
            vector<int> res;
            int carry = 0;
            int n = max(b.num.size(), num.size());

            for (int i=0;i<n;++i){
                int sum = carry;
                if ( i < num.size()) sum+=num[i];
                if ( i < b.num.size()) sum+=b.num[i];
                res.pb( (sum%BASE));
                carry = sum/BASE;
            }
            if ( carry) res.pb(carry);
            return BigNum(res);
        }

};



BigNum dp[105][45];

int main(void){

    int N, K;

    scanf("%d %d", &N, &K);

    for (int i=1;i<=K;++i) dp[1][i] = BigNum(1);


    for (int i=2;i<=N;++i){
        for (int j=1;j<=K;++j){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
        }
    }
    BigNum sum(0);

    for (int i=1;i<=K;++i) sum=sum+dp[N][i];

    printf("%s\n", sum.toString().c_str());
    return 0;
}
