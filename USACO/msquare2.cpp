/*
ID:
PROG:msquare
LANG:C++
*/

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

map<int, int> prev;
map<int, char> operation;
map<int, bool> used;

class MagicSquare
{
    public:
        string first;
        string second;

        MagicSquare(int num)
        {
            char tmp[10];
            sprintf (tmp, "%d", num / 10000);
            first = (string)tmp;

            sprintf(tmp, "%d", num % 10000);
            reverse(tmp, tmp + 4);
            second = (string)tmp;

        }

        void TransformA(){
            string tmp = first;
            first = second;
            second = tmp;
        }

        void TransformB(){
            char tmp1 = first[3];
            char tmp2 = second[3];

            first[3] = first[2];first[2]=first[1];first[1]=first[0];first[0]=tmp1;
            second[3]=second[2];second[2]=second[1];second[1]=second[0];second[0]=tmp2;

        }

        void TransformC(){
            char temp = first[2];
            first[2] = first[1];
            first[1] = second[1];
            second[1] = second[2];
            second[2] = temp;
        }

        string ToString()
        {
            return first + second;
        }

        int ToInt()
        {
            int tmp;
            string temp = second;
            reverse(temp.begin(), temp.end());
            sscanf( (first + temp).c_str(), "%d", &tmp);
            return tmp;
        }

};


int main(void){
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);

    int target = 0, tmp;

    for (int i=0;i<8;++i)
    {
        scanf("%d", &tmp);
        target = target * 10 + tmp;
    }

    MagicSquare square(12345678);
    queue<int> Q;
    Q.push(square.ToInt());

    while ( !Q.empty())
    {
        int num = Q.front();
        Q.pop();

        if ( num == target ) break;

        MagicSquare A(num);A.TransformA();
        MagicSquare B(num);B.TransformB();
        MagicSquare C(num);C.TransformC();

        int numA = A.ToInt();
        int numB = B.ToInt();
        int numC = C.ToInt();

        if ( !used[numA] )
        {
            used[numA] = true;
            prev[numA] = num;
            operation[numA] = 'A';
            Q.push(numA);
        }

        if ( !used[numB] )
        {
            used[numB] = true;
            prev[numB] = num;
            operation[numB] = 'B';
            Q.push(numB);
        }

        if ( !used[numC] )
        {
            used[numC] = true;
            prev[numC] = num;
            operation[numC] = 'C';
            Q.push(numC);
        }

    }

    int current = target;
    string path = "";
    while(current != 12345678)
    {
        path.push_back(operation[current]);
        current = prev[current];
    }
    reverse(path.begin(), path.end());
    cout << path.size()  << endl;
    cout << path << endl;

	return 0;
}
