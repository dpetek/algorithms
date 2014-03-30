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

class MinimumLiars {
public:
    bool isPossible (int numLiars, vector<int> &claim){
        for (int i=0;i<numLiars;++i) if ( claim[i] <= numLiars ) return false;
        for (int i=numLiars;i<claim.size();++i) if ( claim[i] > numLiars ) return false;
        return true;
    }

   int getMinimum( vector <int> claim ) {
        sort(claim.begin(), claim.end(), greater<int>());
        for (int i=claim.size();i>=0;--i){
            if ( isPossible ( i, claim)) return i;
        }
        return -1;
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
			int claim[]               = {1,1,1,2};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MinimumLiars().getMinimum(vector <int>(claim, claim + (sizeof claim / sizeof claim[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int claim[]               = {7,8,1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MinimumLiars().getMinimum(vector <int>(claim, claim + (sizeof claim / sizeof claim[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int claim[]               = {5,5,5,5,5};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MinimumLiars().getMinimum(vector <int>(claim, claim + (sizeof claim / sizeof claim[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int claim[]               = {0,0,0,4,3,0};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MinimumLiars().getMinimum(vector <int>(claim, claim + (sizeof claim / sizeof claim[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int claim[]               = {4,7,5};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = MinimumLiars().getMinimum(vector <int>(claim, claim + (sizeof claim / sizeof claim[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int claim[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinimumLiars().getMinimum(vector <int>(claim, claim + (sizeof claim / sizeof claim[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int claim[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinimumLiars().getMinimum(vector <int>(claim, claim + (sizeof claim / sizeof claim[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int claim[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinimumLiars().getMinimum(vector <int>(claim, claim + (sizeof claim / sizeof claim[0])));
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
