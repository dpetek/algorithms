#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define MOD 4207849484LL

using namespace std;

int main(void){
    freopen("input_2.txt", "r", stdin);
    freopen("output_2.txt","w", stdout);

    int test;
    long long dp[2000];
    scanf("%d", &test);


    int m;
    string s;
    for (int iter=1;iter<=test;++iter){
        cin >> m >> s;
        for (int i=0;i<=s.size();++i)dp[i] = 0LL;
        bool error = false;

        for (int i=0;i<s.size();++i){

            bool found_valid = false;
            int v = 0, pot = 1;
            for (int j=i;j>=0;--j){
                v+=(s[j]-'0')*pot;
                if ( s[j] == '0' ) {pot*=10;continue;}
                if ( v > m) break;

                if ( j == 0){
                    dp[i]+=1LL;
                }else{
                    dp[i]+=dp[j-1];
                    dp[i]%=MOD;
                }
                found_valid = true;
                pot*=10;
            }
            if ( !found_valid){
                error = true;break;
            }

        }
        if ( !error)
            printf ("Case #%d: %lld\n", iter, dp[s.size()-1]);
        else
            printf ("Case #%d: 0\n", iter);
    }


    return 0;
}
