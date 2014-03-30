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

class NumberFinder{
    private:
        bool flag;
        string tmpResult;
        string A;
        string B;

    void find(string num, bool flag, vector<bool> &used){
        if ( num.size() == A.size() && flag ){
            if ( this->tmpResult == "-" ) tmpResult = num;
            else{
                if ( this->completeCmp(num, tmpResult)) tmpResult = num;
            }
            return ;
        }
        int next = num.size();
        if ( !flag){
        bool peq = false;
        for (int i=0;i<B.size();++i){
            if ( next == 0 && B[i] == '0' ) continue;
            if ( used[i] ) continue;
            if (B[i] == A[next] && !peq){
                peq = true;
                string tmp = num;
                tmp.push_back(B[i]);
                used[i] = true;
                find(tmp, flag, used);
                if ( tmpResult != "-") return ;
                used[i] = false;
            }
            if ( cmp(B[i],A[next])){
                string tmp = num;
                tmp.push_back(B[i]);
                used[i] = true;
                find(tmp, true, used);
                used[i] = false;
                break;
            }
        }
        }else{
            for (int i=0;i<B.size();++i){
                if ( !used[i] ){
                    string tmp = num;
                    tmp.push_back(B[i]);
                    used[i] = true;
                    find(tmp, flag, used);
                    used[i] = false;
                }
            }
        }
        return ;
    }

    public:
    NumberFinder(string A, string B){
        this->A = A;
        this->B = B;
        sort(this->B.begin(), this->B.end());
    }

    string findNumber(bool flag){
        this->flag = flag;
        tmpResult = "-";
        vector<bool> used(B.size(), false);
        sort(B.begin(), B.end());
        if( !flag ){
            reverse(B.begin(), B.end());
        }
        find("", false, used);
        if ( tmpResult == "-") return "0";
        return tmpResult;
    }

    bool cmp(char a, char b){
        if ( !flag ) return a < b;
        return a > b;
    }

    bool completeCmp(string s1, string s2){
        if ( !flag ){
            return s1 > s2;
        }
        return s1 < s2;
    }

};

void make_bigger(string num, bool flag, vector<bool>& used){

}

int main(void){
    string A, B;
    cin >> A >> B;
    NumberFinder finder(A,B);

    cout << finder.findNumber(true) << endl;
    cout << finder.findNumber(false) << endl;

	return 0;
}
