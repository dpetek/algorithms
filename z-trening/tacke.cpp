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

class Point{
    public:
        int x,y;

        Point(): x(0), y(0){}
        Point(int _x, int _y) : x(_x), y(_y){}
        Point(pair<int, int> pt) : x(pt.fs), y(pt.sc){}

        Point operator +(const Point &p){
            return Point(x + p.x, y + p.y );
        }

        Point operator -(const Point &p){
            return Point(x - p.x, y - p.y);
        }

        double dist( const Point &p){
            return  sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) );
        }

        double dist2(const pair<double, double> &p){
            return (x - p.fs) * (x - p.fs) + (y - p.sc) * (y - p.sc);
        }

        double dist2 (const Point &p){
            return dist(p);

        }

        int cross(const Point &p){
            return x * p.y - y * p.x;
        }
};

class Node{
public:
    Node *left, *right;
    Point pt;
    Node(){}
    Node(int x, int y){
        this->pt = Point(x,y);
        left = NULL;
        right = NULL;
    }

};

vector<Point> pts1, pts2;

struct Comparator{
    bool axis;
    bool operator () (const Point &p1, const Point &p2){
        if ( axis ) return p1.x < p2.x;
        return p1.y < p2.y;
    }
};

Node *root;
Node *root2;
double maxyDist = 0.0;

Node* constructTree(vector<Point> :: iterator begin, vector<Point> :: iterator end, bool axis){
    if ( begin == end ) return NULL;
    Comparator cmp;
    cmp.axis = axis;

    sort(begin, end, cmp);

    Point median = *(begin + (end-begin)/2);

    Node *nd = new Node(median.x,median.y);

    nd->left = constructTree(begin,begin + (end-begin)/2, !axis);
    nd->right = constructTree(begin + (end-begin)/2+1, end, !axis);

    printf ("(%d %d)", nd->pt.x, nd->pt.y);
    if ( nd->left != NULL ) printf ("  L(%d %d)", nd->left->pt.x, nd->left->pt.y);
    if ( nd->right != NULL) printf ("  R(%d %d)", nd->right->pt.x, nd->right->pt.y);
    printf ("\n");

    return nd;
}

void releaseTree(Node *root){
    if (root == NULL ) return;

    Node *left = root->left;
    Node *right = root->right;
    delete root;
    releaseTree(left);
    releaseTree(right);
}

void checkMax(Node *root, Point &pt, bool axis){
    if ( root == NULL ) return ;

    double dst = pt.dist(root->pt);
    maxyDist = max(maxyDist,dst);

    if ( axis ){
        if ( root->left != NULL && abs(pt.x - root->pt.x) <= abs(root->left->pt.x-pt.x)){
            checkMax(root->left, pt, !axis);
        }
        if ( root->right != NULL && abs(pt.x - root->pt.x) <= abs(root->right->pt.x-pt.x)){
            checkMax(root->right, pt, !axis);
        }
    }else{
        if ( root->left != NULL && abs(pt.y - root->pt.y) <= abs(root->left->pt.y-pt.y)){
            checkMax(root->left, pt, !axis);
        }
        if ( root->right != NULL && abs(pt.y - root->pt.y) <= abs(root->right->pt.y-pt.y)){
            checkMax(root->right, pt, !axis);
        }
    }


}

double bruteForce(){
    double maxy = 0.0;
    for (int i=0;i<pts1.size();++i){
        for (int j=0;j<pts2.size();++j){
            printf ("(%d %d) - (%d %d) %lf\n", pts1[i].x, pts1[i].y, pts2[j].x, pts2[j].y, pts1[i].dist(pts2[j]));
            maxy = max(maxy, pts1[i].dist(pts2[j]));
        }
    }
    return maxy;
}

int main(void){
    int n , m, x, y;

//    scanf ("%d", &n);
//    for (int i=0;i<n;++i){
//        scanf("%d %d", &x, &y);
//        pts1.pb(Point(x,y));
//    }
//
//    root = constructTree(pts1.begin(), pts1.end(), true);
//    root2 = constructTree(pts1.begin(), pts1.end(), false);
//    scanf("%d", &m);
//
//    for (int i=0;i<m;++i){
//        scanf("%d %d", &x, &y);
//        Point toCheck(x,y);
//        checkMax(root->left, toCheck, false);
//        checkMax(root->right, toCheck, false);
//        checkMax(root2->left, toCheck, true);
//        checkMax(root2->right, toCheck, true);
//    }
//    releaseTree(root);
//    releaseTree(root2);

    srand(time(0));
    double kdtree, bforce;
    int iter = 0;
    do{
        pts1.clear();
        pts2.clear();
        ++iter;
        n = rand() % 5 + 5;
        m = rand() % 5 + 2;
        for (int i=0;i<n;++i){
            pts1.pb(Point(rand() % 10, rand() % 10));

        }
        for (int j=0;j<m;++j){
            pts2.pb(Point(rand() % 10, rand() % 10));
        }

        bforce = bruteForce();
        maxyDist = 0.0;

        root=constructTree(pts1.begin(), pts1.end(), true);
        printf ("--\n");
//        root2 = constructTree(pts1.begin(), pts1.end(), false);


        for (int i=0;i<m;++i){
            maxyDist = max(maxyDist, root->pt.dist(pts2[i]));
            checkMax(root->left, pts2[i], false);
            checkMax(root->right, pts2[i], false);
//            checkMax(root2->left, pts2[i], true);
//            checkMax(root2->right, pts2[i], true);
        }
        kdtree = maxyDist;
        releaseTree(root);
        releaseTree(root2);
    }while(abs(kdtree-bforce)<1e-7);

    for (int i=0;i<n;++i) printf ("%d %d\n", pts1[i].x, pts1[i].y);
    printf ("--\n");
    for (int i=0;i<m;++i) printf ("%d %d\n", pts2[i].x, pts2[i].y);

    printf ("%d) [%d %d] %lf %lf\n",iter, n, m, bforce, kdtree);
    printf ("%.3lf\n", maxyDist);
    return 0;
}
