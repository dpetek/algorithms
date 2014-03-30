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
        static const int BASE = 10000000;

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
                else sprintf (buffer, "%s%07d", buffer, num[i]);
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


BigNum dp[502][502];

int main(void){
    int n, m;



    scanf ("%d %d", &n, &m);
    m=m*2+1;
    dp[0][m/2]=BigNum(1);

    for (int row = 1;row<=n;++row){
        for (int col=0;col<m;++col){
            dp[row][col] = (col>0 ? dp[row-1][col-1] : BigNum(0))+(col+1<m ? dp[row-1][col+1] : BigNum(0))+dp[row-1][col];
        }
    }
    BigNum sum(0);
    for (int i=0;i<m;++i) {
        sum=sum + dp[n][i];
    }
    cout << sum.toString() << endl;

    return 0;
}
