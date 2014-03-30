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
    string s;

    cin >> s;

    if ( s == "::"){
        for (int i=0;i<8;++i){
            printf ("%s%s", i ? ":" : "", "0000");
        }
        return 0;
    }

    vector<string> parts;
    split_string(s, ':', parts);

    vector<string> real;
    int zerosIndex = -1;
    for (int i=0;i<parts.size();++i){
        if ( parts[i].size()){
            real.push_back(string(4 - parts[i].size(), '0') + parts[i]);
        }else{
            if ( ! i ) continue;
            zerosIndex = real.size();
        }
    }

    int diff = 8 - real.size();

    for (int i=0;i<diff;++i) real.insert(real.begin() + zerosIndex, "0000");

    for (int i=0;i<real.size();++i){
        printf ("%s%s", i ? ":" : "", real[i].c_str());
    }
	return 0;
}
