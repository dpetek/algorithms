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

class LuckyRemainder {
public:
    int my_pow(int a, int b){
        int ret = 1;
        for (int i=0;i<b;++i) {ret*=a;ret%=9;}
        return ret;
    }

   int getLuckyRemainder( string X ) {

        int sum = 0;

        for (int i=0;i<X.size();++i) sum+=(X[i]-'0') * my_pow(2, X.size()-1);;

        return sum%9;
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
			string X                  = "123";
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string X                  = "24816";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string X                  = "8";
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string X                  = "11235813213455";
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			string X                  = "112358132134551123581321345511235813213455112358132134551123581321345511235813213455";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 5: {
			string X                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string X                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
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
