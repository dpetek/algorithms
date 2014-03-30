#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#define MOD 4207849484LL

#define MAX_VALUE 10000001

using namespace std;

string seq;
int iter_index;
int seq_index;

int solution[100000];

vector<int> segments;
vector<int> iter_part;

void calc(vector<int> v,int start, int end){
    if ( !v.size()) return ;
    if ( v.size() == 1){solution[start] = v[0];return;}
    //proces root
    int left_cnt = v.size() / 2;
    int right_cnt = (v.size() + 1) / 2, index = 0;
    vector<int> left_part, right_part;
    for (int i=0;i<iter_part[iter_index];++i){
        int ii = seq_index - iter_part[iter_index] + i + 1;
        if ( seq[ii] == '2'){
            right_part.push_back(v[index++]);
            --right_cnt;
        }else{
            left_part.push_back(v[index++]);
            --left_cnt;
        }
    }
    seq_index-=iter_part[iter_index];
    --iter_index;


//    printf ("\n");fflush(stdout);


    if ( right_cnt ){
        for (;index<v.size();++index) right_part.push_back(v[index]);
    }
    if( left_cnt ){
        for (;index<v.size();++index) left_part.push_back(v[index]);
    }

    //proces right child
    calc(right_part,end-right_part.size(), end);

    //proces left child
    calc(left_part, start, start + left_part.size());

}



void get_segments_list(int sz){
    if ( sz <= 1 ) return ;


    int s1 = sz/2;
    int s2 = (sz + 1) / 2;

    if ( s1 > 1 ) get_segments_list(s1);
    if ( s2 > 1 ) get_segments_list(s2);

    segments.push_back(sz);
}

void calc_iter_part(){
    int seq_iter = 0;
    for (int i=0;i<segments.size();++i){
        int sz = segments[i];
        int l = sz / 2;
        int r = (sz+1)/2;
        int cnt = 0;
        for(;seq_iter<seq.size();++seq_iter){
            if ( !l || !r ) break;
            ++cnt;
            if ( seq[seq_iter] == '1')--l;
            else --r;
        }
        iter_part.push_back(cnt);
    }
}

int encode(int n){
    int res = 1;
    for (int i=0;i<n;++i){
        res = (31 * res + solution[i]) % 1000003;
    }
    return res;
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);

    int test;
    int s;
    scanf("%d", &test);


    for (int iter=1;iter<=test;++iter){
        int n;
        cin >> n >> seq;
        vector<int> v;
        segments.clear();
        iter_part.clear();
        for (int i=0;i<n;++i)solution[i] = -1;
        for (int i=1;i<=n;++i){
            v.push_back(i);
        }
        get_segments_list(v.size());
        calc_iter_part();
        iter_index = iter_part.size()-1;
        seq_index = seq.size() - 1;
        calc(v, 0, v.size());
        printf ("Case #%d: %d\n", iter, encode(n));
    }

    return 0;
}
