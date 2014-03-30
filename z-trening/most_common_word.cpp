#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>
#include <cctype>
#define pb push_back
#define fs first
#define sc second

using namespace std;

void split_string(string s, string c, vector<string>& container){

    string buffer = "";
    container.clear();

    for (int i=0;i<s.size();++i){
        if ( find(c.begin(), c.end(), s[i]) != c.end()){
            container.push_back(buffer);
            buffer = "";
        }else{
            buffer.push_back(s[i]);
        }
    }

    if ( buffer.size()) container.push_back(buffer);
    return ;
}

char buffer[2000];
map<string, int> cnt;

void addWord(string w){
    for(int i=0;i<w.size();++i) w[i] = tolower(w[i]);
    ++cnt[w];
}

int main(void){
    vector<string> container;


    while ( scanf("%s", buffer) == 1){
        split_string((string)buffer, " .,?", container);

        for (int i=0;i<container.size();++i){
            if ( !container[i].size() ) continue;
            addWord(container[i]);
        }
    }
    int maxy = -1;
    string winner;
    for(map<string, int> :: iterator it = cnt.begin(); it != cnt.end(); ++it){
        if ( it->second > maxy ){
            maxy = it->second;
            winner = it->first;
        }
    }
    printf ("%s %d\n", winner.c_str(), maxy);
	return 0;
}
