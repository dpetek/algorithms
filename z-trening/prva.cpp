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

string word = "";

void split_string(string s, char c, vector<string>& container){

    string buffer = "";
    container.clear();

    for (int i=0;i<s.size();++i){
        if ( s[i] == c){
            container.push_back(buffer);
            buffer = "";
        }else{
            buffer.push_back(s[i]);
        }
    }

    if ( buffer.size()) container.push_back(buffer);
    return ;
}


int main(void){

    int n, m;
    cin >> n >> m;
    string row;
    vector<string> container;
    vector<string> crossword;

    for (int i=0;i<n;++i){
        cin >> row;
        crossword.push_back(row);
        split_string(row, '#', container);
        for (int j=0;j<container.size();++j){
            if ( container[j].size() < 2 ) continue;
            if ( word == "" || container[j] < word ) word = container[j];
        }
    }

    for (int col=0;col<m;++col){
        string tmp = "";
        for (int r=0;r<n;++r){
            tmp+=crossword[r][col];
        }
        split_string(tmp, '#', container);
        for (int j=0;j<container.size();++j){
            if ( container[j].size() < 2 ) continue;
            if ( word == "" || container[j] < word ) word = container[j];
        }
    }

    cout << word << endl;
	return 0;
}
