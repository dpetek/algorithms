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

int getQuadrant(pair<int,int> point){
    if ( point.fs >= 0 && point.sc > 0 ) return 1;
    if ( point.fs >= 0 && point.sc < 0 ) return 4;
    if ( point.fs <= 0 && point.sc > 0 ) return 2;
    return 3;
}

class Quad{
    public:
    int q1, q2, q3, q4;
    Quad(){}
    Quad(int n1, int n2, int n3, int n4):q1(n1), q2(n2), q3(n3), q4(n4){}
};

class TreeNode{
public:
    Quad Q;
    int start, end;
    TreeNode(Quad q, int s, int e) : Q(q), start(s), end(e){}
};

class IntervalTree{
    Quad *root;

public:
    void constructTree(vector<pair<int,int> > &v){

    }

    TreeNode* construct(TreeNode *root, vector<pair<int,int> > &v, int start, int end){

        if (start == end){
            Quad q;
            int quadrant = getQuadrant(v[start]);
            if ( quadrant == 1) q.q1 = 1;
            if ( quadrant == 2) q.q2 = 1;
            if ( quadrant == 3) q.q3 = 1;
            if ( quadrant == 4) q.q4 = 1;
            TreeNode *node = new TreeNode(q, start, end);
            return root = node;
        }




    }

};

int main(void){

	return 0;
}
