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
#define INF (1<<29)
using namespace std;

int dist[26][26];
int er[26];
int add[26];

class PalindromizationDiv1 {
public:
   int palindromize(string &s){
        for (int mid =0;mid<s.size();++mid){

        }
   }

   int getMinimumCost( string word, vector <string> operations ) {
        int cost;
        char c1, c2;
        char tmp[20];

        for (int i=0;i<26;++i){
            er[i] = INF;
            add[i] = INF;
            for(int j=0;j<26;++j)
                dist[i][j] = INF;
        }

        for (int i=0;i<operations.size();++i){
            sscanf (operations[i].c_str(), "%s", tmp);
            if ( string(tmp) == "change"){
                sscanf(operations[i].c_str(), "%*s %c %c %d", &c1, &c2, &cost);
                dist[c1-'a'][c2-'a'] = cost;
            }else if ( string(tmp) == "erase"){
                sscanf (operations[i].c_str(), "%*s %c %d", &c1, &cost);
                er[c1-'a'] = cost;
            }else{
                sscanf (operations[i].c_str(), "%*s %c %d", &c1, &cost);
                add[c1-'a'] = cost;
            }
        }

        for (int k=0;k<26;++k){
            for (int i=0;i<26;++i){
                for (int j=0;j<26;++j){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for (int i=0;i<26;++i){
            for (int j=0;j<26;++j){
                er[i] = min(er[i], dist[i][j] + er[j]);
            }
        }

        return 0;
   }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}

	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}

		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;

		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl;
			cerr << "    Received: " << received << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string word               = "racecar";
			string operations[]       = {};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PalindromizationDiv1().getMinimumCost(word, vector <string>(operations, operations + (sizeof operations / sizeof operations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string word               = "topcoder";
			string operations[]       = {"erase t 1", "erase o 1", "erase p 1", "erase c 1", "erase d 1", "erase e 1", "erase r 1"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = PalindromizationDiv1().getMinimumCost(word, vector <string>(operations, operations + (sizeof operations / sizeof operations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string word               = "topcoder";
			string operations[]       = {"erase t 10", "erase o 1", "erase p 1", "erase c 1", "erase d 1", "erase e 1", "erase r 1"};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = PalindromizationDiv1().getMinimumCost(word, vector <string>(operations, operations + (sizeof operations / sizeof operations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string word               = "caaaaaab";
			string operations[]       = {"change b a 100000", "change c a 100000", "change c d 50000", "change b e 50000", "erase d 50000", "erase e 49999"};
			int expected__            = 199999;

			clock_t start__           = clock();
			int received__            = PalindromizationDiv1().getMinimumCost(word, vector <string>(operations, operations + (sizeof operations / sizeof operations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string word               = "moon";
			string operations[]       = {"erase o 5", "add u 7", "change d p 3", "change m s 12", "change n d 6", "change s l 1"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = PalindromizationDiv1().getMinimumCost(word, vector <string>(operations, operations + (sizeof operations / sizeof operations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string word               = ;
			string operations[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PalindromizationDiv1().getMinimumCost(word, vector <string>(operations, operations + (sizeof operations / sizeof operations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string word               = ;
			string operations[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PalindromizationDiv1().getMinimumCost(word, vector <string>(operations, operations + (sizeof operations / sizeof operations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string word               = ;
			string operations[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PalindromizationDiv1().getMinimumCost(word, vector <string>(operations, operations + (sizeof operations / sizeof operations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
