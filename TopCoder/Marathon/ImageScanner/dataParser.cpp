#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <set>
#define pb push_back

using namespace std;

map<pair<string,string>, set<string> > mapa;
char tmp[40];


int str2bin(string s){
    int ret = 0,pot= 1;

    for (int i=s.size()-1;i>=0;--i){
        ret+=(s[i]-'0') * pot;
        pot*=2;
    }
    return ret;
}

int main(void){
    FILE *fout = fopen("data.txt","w");
    FILE *fconf = fopen("conflict.txt", "w");

        for (int i='A';i<='Z';++i){
            for (int k=0;k<2;++k){
                for (int j=8;j<=28;++j){

                    char name[30];
                    sprintf (name, "letters/%c%c%d.txt", i, k ? 'P' : 'B', j);
                    printf ("%s\n", name);fflush(stdout);
                    FILE *fin = fopen (name,"r");

                        int n, m;
                        vector<string> v;
                        fscanf(fin, "%d %d", &n, &m);
                        fprintf (fout, "%d,%d", n, m);
                        for (int i=0;i<n;++i){
                            fscanf(fin,"%s",tmp);
                            fprintf(fout, ",%d", str2bin(tmp));
                        }

                    fclose(fin);
                }
            }
            fprintf ( fout, "\n");

        }

    fclose(fconf);
    fclose(fout);
    return 0;
}
