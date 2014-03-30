#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define pb push_back
#define fs first
#define sc second

using namespace std;

#define MAX 100001

int case00[MAX + 1];
int case11[MAX + 1];
string num[2];

void addCase00(int n){
//    printf ("\t>Adding case 00 to %d\n", n );
    while ( n <= MAX){
        ++case00[n];
        n+=n&(-n);
    }
}
void removeCase00(int n){
//    printf ("\t>Removing case 00 from %d\n", n);
    while (n > 0 ){
        --case00[n];
        n-=n&(-n);
    }
}

void addCase11(int n){
//    printf ("\t>Adding case 11 to %d\n", n);
    while (n<=MAX){
        ++case11[n];
        n+=n&(-n);
    }
}
void removeCase11(int n){
//    printf ("\t>Removing case 11 from %d\n", n);
    while(n>0){
        --case11[n];
        n-=n&(-n);
    }
}

int getCase00Cnt(int n){
    int sum = 0;
    if ( n <= 0 ) return 0;
    while(n>0){
        sum+=case00[n];
        n-=n&(-n);
    }
    return sum;
}

int getCase11Cnt(int n){
    int sum = 0;
    if ( n <= 0 ) return 0;
    while ( n > 0 ){
        sum+=case11[n];
        n-=n&(-n);
    }
    return sum;
}

int getNth00(int n){
    int L = 0, H = MAX, M;
    for (int i=0;i<30;++i){
        M = ( L + H ) / 2;
        if ( getCase00Cnt(M) >= n ) H = M;
        else L = M;
    }
//    printf ("Nth (%d) position 00 is %d\n", n, M);
    return M;
}
int getNth11(int n){
    int L = 0, H = MAX, M;
    for (int i=0;i<30;++i){
        M = ( L + H ) / 2;
//        printf ("%d %d(%d) %d\n", L, M , getCase11Cnt(M), H);
        if ( getCase11Cnt(M) >= n ) H = M;
        else L = M+1;
    }
//    printf ("Nth (%d) position 11 is %d\n", n, M);
    return M;
}

int getBit2(int pos){
    int c = 0;

    for (int i=0;i<pos;++i){
        c = (c + num[0][i] - '0' + num[1][i] - '0')/2;
    }
    return (num[0][pos] - '0' + num[1][pos] - '0' + c) % 2;
}


string genRandomNumber(int n){

    string s = "";
    for(int i=0;i<n;++i){
        if ( rand() % 2 == 0 ) s.push_back('0');
        else s.push_back('1');
    }
    return s;
}

int changeBit(int index, int pos, int bit){
//    printf ("Changing %d %d %d\n", index, pos, bit);
    if ( num[0][pos] == '0' && num[1][pos] == '0' ) removeCase00(pos);
    if ( num[0][pos] == '1' && num[1][pos] == '1' ) removeCase11(pos);

    num[index][pos] = (char)(bit + '0');

    if ( num[0][pos] == '0' && num[1][pos] == '0' ) addCase00(pos);
    if ( num[0][pos] == '1' && num[1][pos] == '1' ) addCase11(pos);

}

int getBit(int n){
    if ( n == 0 ) return 0;
    if ( n == 1 ) return (num[0][1] - '0' + num[1][1] - '0') % 2;
    if ( n >= num[0].size()) return 0;
    int c00 = getCase00Cnt(n - 1);
    int c11 = getCase11Cnt(n - 1);
    int c = 0;
        int n00 = getNth00(c00);
        int n11 = getNth11(c11);
        if ( n00 == 0 && n11 != 0 ) c = 1;
        else
        if ( n00 != 0 && n11 == 0 ) c = 0;
        else
        if ( n00 == 0 && n11 == 0 ) c = 0;
        else
        if ( n00 >= n11 ) c = 0;
        else c = 1;
//    printf ("c == %d\n", c);
    return (num[0][n] - '0' + num[1][n] - '0' + c) % 2;

}



bool checkRandom(){
    num[0].clear();
    num[1].clear();
    for (int i=0;i<=MAX;++i) {
        case00[i] = 0;
        case11[i] = 0;
    }
//    num[0] = genRandomNumber(5);
//    num[1] = genRandomNumber(5);
    num[0] = "00000";
    num[1] = "11111";

    cout << "Num1: " << num[0] << endl;
    cout << "Num2: " << num[1] << endl;
    cout << "      54321" << endl;

    reverse(num[0].begin(), num[0].end());
    reverse(num[1].begin(), num[1].end());
    num[0] = "0" + num[0] + "0";
    num[1] = "0" + num[1] + "0";

    for (int i=1;i<num[0].size();++i){
        if ( num[0][i] == '0' && num[1][i] == '0') addCase00(i);
        if ( num[0][i] == '1' && num[1][i] == '1') addCase11(i);
    }
    bool ok = true;

//    for (int i=0;i<3;++i){
//        int index = rand() % 2;
//        int bit = rand() % 2 + '0';
//        int pos = rand() % (num[0].size() - 2) + 1;
//
//        printf ("[%d]Changing bit %d from %c to %c\n", index, pos, num[index][pos], bit);
//
//        changeBit(index, pos, bit);
//    }

    for (int i=0;i<num[0].size();++i){
        printf ("(%d)[%c + %c] = %d vs %d\n", i, num[0][i], num[1][i], getBit(i), getBit2(i));
        if ( getBit(i) != getBit2(i)) ok = false;
    }

    printf ("%s\n", ok ? "PASS" : "FAIL");fflush(stdout);
    return ok;
}

int main(void){

    int n, m;
    char command[20];
    scanf("%d %d", &n, &m);

    cin >> num[0];
    cin >> num[1];

    reverse(num[0].begin(), num[0].end());
    reverse(num[1].begin(), num[1].end());
    num[0] = "0" + num[0] + "0";
    num[1] = "0" + num[1] + "0";

    for (int i=1;i<num[0].size();++i){
        if ( num[0][i] == '0' && num[1][i] == '0') addCase00(i);
        if ( num[0][i] == '1' && num[1][i] == '1') addCase11(i);
    }

    for (int i=0;i<m;++i){
        int a, b;
        scanf("%s", command);
        if ( command[0] == 's'){
            scanf("%d %d", &a, &b);
            if ( command[4] == 'a') {
                 changeBit(0, a+1,b);
            }else{
                 changeBit(1, a+1,b);
            }

        }else{
            scanf("%d", &a);
            printf ("%d", getBit(a+1));
        }
    }

	return 0;
}
