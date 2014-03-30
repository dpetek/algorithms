#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define fs first
#define sc second

using namespace std;

class Node{
public:
    vector<Node> nodes;
    char value;
    Node(){
        this->value = '.';
    }
    Node(char c) : value(c){}
};


class Trie{
private:
    Node _root;

public:
    Trie(){

    }

    void AddString(string& s){
        Node *trie = &_root;
        for (int i=0;i<=s.size();++i){
            bool found = false;
            char c;

            if ( i < s.size() ) c = s[i];
            else c = ',';

            for (int j=0;j<trie->nodes.size();++j){
                if ( trie->nodes[j].value == c){
                    found = true;
                    trie = &trie->nodes[j];
                    break;
                }
            }

            if ( !found ){
                Node newNode(c);
                trie->nodes.push_back(newNode);
                trie = &trie->nodes[trie->nodes.size()-1];
            }
        }
    }

    void PrintTrie(){
        this->printTrie(this->_root);
    }

    string BestAppend(string s){
        Node *trie = &_root;
        string ret = "";
        string foundBest = "-";
        for (int i=0;i<s.size();++i){
            bool found = false, foundEnd = false;
            string orgString = ret;
            for (int j=0;j<trie->nodes.size();++j){
                if ( trie->nodes[j].value == ',')foundEnd = true;
            }
            for (int j=0;j<trie->nodes.size();++j){
                if ( trie->nodes[j].value == s[i]){
                    found = true;
                    ret.push_back(trie->nodes[j].value);
                    trie = &trie->nodes[j];
                    break;
                }
            }

            if (foundEnd){
                foundBest = orgString;
            }

            if ( !found ) break;
        }
        if ( foundBest.size() == s.size()) return "-";
        return foundBest;
    }

private:
    void printTrie(Node n){
        printf ("%c->", n.value);

        for (int i=0;i<n.nodes.size();++i){
            printTrie(n.nodes[i]);
        }
    }

};

char buffer[1005];
Trie T;
Trie Trev;
int main(void){
    int n, m;

    scanf("%d", &n);

    for (int i=0;i<n;++i){
        scanf("%s", buffer);
        string sbuffer = (string)buffer;
        string rbuffer = string(sbuffer.rbegin(), sbuffer.rend());
        T.AddString(sbuffer);
        Trev.AddString(rbuffer);
    }

    scanf("%d", &m);

    for (int i=0;i<m;++i){
        scanf("%s", buffer);

        string sbuffer = (string)buffer;
        string rbuffer = string(sbuffer.rbegin(), sbuffer.rend());

        string bestAppend = T.BestAppend(sbuffer);
        string bestPrepand = Trev.BestAppend(rbuffer);
        string rbestPrepand = string(bestPrepand.rbegin(), bestPrepand.rend());

        if ( bestAppend == "-") bestAppend = "ne postoji";
        if ( rbestPrepand == "-") rbestPrepand = "ne postoji";

        printf("%s %s\n", bestAppend.c_str(), rbestPrepand.c_str());
    }

    return 0;
}
