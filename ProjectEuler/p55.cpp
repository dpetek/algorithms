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

class BigNum{
    private:
        vector<int> num_;
        static const int BASE_ = 10000;

        int operator [](int index) const{
            return num_[index];
        }

    public:
        BigNum(int n){
            do{
                num_.push_back(n % BASE_);
                n/=BASE_;
            }while(n);
        }
        BigNum(const std::vector<int> &v){
            this->num_ = vector<int>(v);
        }

        BigNum(string s){

            for (int i=s.size()-1;i>=0;i-=4){
                int tmp = 0;
                if ( i-3 >= 0 ) tmp = tmp * 10 + s[i-3] - '0';
                if ( i-2 >= 0 ) tmp = tmp * 10 + s[i-2] - '0';
                if ( i-1 >= 0 ) tmp = tmp * 10 + s[i-1] - '0';
                if ( i-0 >= 0 ) tmp = tmp * 10 + s[i-0] - '0';
                this->num_.push_back(tmp);
            }

        }

        BigNum operator +(const BigNum b){
            int n = std::max(this->size(), b.size());
            int s1 = this->size(), s2 = b.size();
            vector<int> tmp;
            int c = 0;
            for (int i=0;i<n;++i){
                int v1 = 0, v2 = 0;
                if ( i < s1 ) v1 = (*this)[i];
                if ( i < s2 ) v2 = b[i];

                tmp.push_back( (v1 + v2 + c) % this->BASE_);
                c = (v1 + v2 + c) / this->BASE_;
            }

            if ( c ) tmp.push_back(c);
            return BigNum(tmp);
        }

        string ToString(){
            char buffer[300] = {0};
            for (int i=this->num_.size()-1;i>=0;--i){
                if ( i != this->num_.size()-1 )
                sprintf(buffer, "%s%04d", buffer, num_[i]);
                else
                sprintf(buffer, "%s%d", buffer, num_[i]);
            }
            return buffer;
        }

        int size() const{
            return num_.size();
        }
};

bool isPalin(string s){
    for (int i=0;i*2<s.size();++i){
        if ( s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

bool isL(int n){
    BigNum b(n);
    for (int i=0;i<50;++i){
        string s = b.ToString();
        reverse(s.begin(), s.end());

        b = b + BigNum(s);
        if ( isPalin(b.ToString())) return true;
    }
    return false;
}


int main(void){

    int cnt = 0;
    for (int i=0;i<10000;++i){
        cnt+= (!isL(i));
    }
    printf ("%d\n", cnt);
	return 0;
}
