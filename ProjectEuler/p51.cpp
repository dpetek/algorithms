#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> primes;
vector<char> isPrime;

string num2str(int num){
    char buffer[20];
    sprintf (buffer, "%d", num);
    return buffer;
}

int str2num(string& s){
    int n;
    sscanf(s.c_str(), "%d", &n);
    return n;
}

void sieve(int n){
    isPrime = vector<char>(n, '.');

    for (int i=2;i*i<=n;++i){
        if ( isPrime[i] == '.'){
            for(int j=i+i;j<=n;j+=i){
                isPrime[j] = 'x';
            }
        }
    }
    for (int i=2;i<=n;++i){
        if ( isPrime[i] == '.') primes.push_back(i);
    }
}

int check(string s, bool print = false){
    int cnt = 0;
    for (int i=0;i<=9;++i){
        int value = 0;
        for (int j=0;j<s.size();++j){
            if ( j==0 && s[j] == '*' && i == 0 ) {value = -1;break;}
            if ( s[j] != '*' ) value = value * 10 + s[j] - '0';
            else value = value * 10 + i;

        }
        if ( print ) printf ("\t%d %d\n", value, value != -1 && isPrime[value] == '.');
        if ( value > 1 && isPrime[value] == '.' ) ++cnt;
    }
    return cnt;
}


int main(void){

    sieve(100000000);


    for (int i=1000;i<primes.size();++i){
        int p = primes[i];
        string s = num2str(p);
        int n = s.size();
        for (int mask=1;mask<(1<<n);++mask){
            string tmp = s;
            for (int j=0;j<n;++j){
                if ( mask&(1 << j ))tmp[j] = '*';
            }
            if ( check(tmp) == 8 ) {
                check(tmp, true);
                printf ("%s %s %d\n",s.c_str(), tmp.c_str(),  i);
                return 0;
            }
        }


    }

    return 0;
}
