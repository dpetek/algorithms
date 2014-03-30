#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define fs first
#define sc second

using namespace std;

long long grid[1001][1001]; //15.3 Mb

long long H[1001];
long long V[1001];
long long D1[3000];
long long D2[3000];

vector<pair<pair<int,int>,long long> > candidates;

long long maxy = 0LL;
int type;
int lrow, lcol;
int n, m;

void check(long long value, int t,int row, int col){
    if ( value > maxy ){
        maxy = value;
        ::type = t;

        lrow = row;
        lcol = col;

    }
}

string decodeType(int t){
    switch(t){
        case 10: return "right";
        case 11: return "left";
        case 12: return "right";

        case 20: return "down";
        case 21: return "up";
        case 22: return "down";

        case 30: return "up-right";
        case 31: return "up-right";
        case 32: return "down-left";

        case 40: return "up-left";
        case 41: return "up-left";
        case 42: return "down-right";

    }
}

int main(void){
    scanf("%d %d", &n, &m);

    for (int row=0;row<n;++row){
        for (int col=0;col<m;++col){
            scanf("%lld", &grid[row][col]);
        }
    }

    /**
        HORIZONTALNO
    */
    candidates.clear();
    for (int row=0;row<n;++row){
        for (int col=0;col<m;++col){
            H[row] += grid[row][col];
            if ( grid[row][col] == 0LL){
                candidates.push_back(make_pair(make_pair(row,col), H[row]));
            }
        }
        check(H[row], 10, row, -1);
    }
    for (int i=0;i<candidates.size();++i){
        long long v1 = candidates[i].sc;
        long long v2 = H[candidates[i].fs.fs] - v1;
        check(v1, 11, candidates[i].fs.fs, candidates[i].fs.sc);
        check(v2, 12, candidates[i].fs.fs, candidates[i].fs.sc);
    }


    /**
        VERTIKALNO
    */
    candidates.clear();
    for (int row=0;row<n;++row){
        for (int col=0;col<m;++col){
            V[col] += grid[row][col];
            if ( grid[row][col] == 0LL){
                candidates.push_back(make_pair(make_pair(row,col), V[col]));
            }
            if ( row+1==n){
                check(V[col], 20, -1, col);
            }
        }

    }
    for (int i=0;i<candidates.size();++i){
        long long v1 = candidates[i].sc;
        long long v2 = V[candidates[i].fs.sc] - v1;
        check(v1, 21, candidates[i].fs.fs, candidates[i].fs.sc);
        check(v2, 22, candidates[i].fs.fs, candidates[i].fs.sc);
    }


    /**
        GLAVNA DIJAGONALA
    */
    candidates.clear();
    for (int row=0;row<n;++row){
        for (int col=0;col<m;++col){
            D1[row+col] += grid[row][col];
            if ( grid[row][col] == 0LL){
                candidates.push_back(make_pair(make_pair(row,col), D1[row+col]));
            }
            if(row+1==n){
                check(D1[row+col], 30, row+1, col-1);
            }

            if(col==0){
                check(D1[row+col], 30, row+col-1, -1);
            }
        }
    }

    for (int i=0;i<candidates.size();++i){
        long long v1 = candidates[i].sc;
        long long v2 = D1[candidates[i].fs.fs + candidates[i].fs.sc] - v1;
        check(v1, 31, candidates[i].fs.fs, candidates[i].fs.sc);
        check(v2, 32, candidates[i].fs.fs, candidates[i].fs.sc);
    }


    /**
        SPOREDNA DIJAGONALA
    */
    candidates.clear();
    for (int row=0;row<n;++row){
        for (int col=0;col<m;++col){
            D2[row-col+1001] += grid[row][col];
            if ( grid[row][col] == 0LL){
                candidates.push_back(make_pair(make_pair(row,col), D2[row-col+1001]));
            }

            if ( row+1==n){
                check(D2[row-col+1001], 40, row+1, col+1);
            }
            if (col+1==m){
                check(D2[row-col+1001], 40, row+1, col+1);
            }
        }
    }



    for (int i=0;i<candidates.size();++i){
        long long v1 = candidates[i].sc;
        long long v2 = D2[candidates[i].fs.fs - candidates[i].fs.sc + 1001] - v1;
        check(v1, 41, candidates[i].fs.fs, candidates[i].fs.sc);
        check(v2, 42, candidates[i].fs.fs, candidates[i].fs.sc);
    }



    printf ("%d %d\n%s\n", lrow+1, lcol+1, decodeType(::type).c_str(), maxy);

    return 0;
}
