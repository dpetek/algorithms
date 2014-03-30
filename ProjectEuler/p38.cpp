#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string num2str(int num){
    char buffer[20];
    sprintf (buffer, "%d", num);
    return buffer;
}

int main(void){

    string s="987654321";
int iter = 0;
    do{

        int n;
        sscanf(s.c_str(), "%d", &n);
        bool matched = false;
        for (int i=1;i<=5;++i){
            string cand = s.substr(0, i);
            int c;
            sscanf(cand.c_str(), "%d", &c);

            int index = i;
            string tmp = cand;
            for (int k=2;;++k){
                int m = c * k;
                tmp+=num2str(m);
                if ( tmp == s){
                    matched = true;
                    break;
                }
                if ( tmp.size() >= s.size()) break;
            }
            if ( matched){
                printf ("%d %s\n", c, s.c_str());
                exit(1);
            }
        }

        if ( iter % 100 == 0 ) printf ("%d/%d  %s\n",iter, 2*3*4*5*6*7*8*9, s.c_str());
        ++iter;
    }while(prev_permutation(s.begin(), s.end()));

    return 0;
}
