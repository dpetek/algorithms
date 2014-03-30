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

class NumberLabyrinthDiv1 {
public:
   int getNumberOfPaths( vector <int> X, vector <int> Y, vector <int> val, int xFinish, int yFinish, int K ) {

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
			int X[]                   = {};
			int Y[]                   = {};
			int val[]                 = {};
			int xFinish               = 3;
			int yFinish               = 3;
			int K                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = NumberLabyrinthDiv1().getNumberOfPaths(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), xFinish, yFinish, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int X[]                   = {};
			int Y[]                   = {};
			int val[]                 = {};
			int xFinish               = 3;
			int yFinish               = 3;
			int K                     = 3;
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = NumberLabyrinthDiv1().getNumberOfPaths(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), xFinish, yFinish, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int X[]                   = {2};
			int Y[]                   = {2};
			int val[]                 = {1};
			int xFinish               = 3;
			int yFinish               = 3;
			int K                     = 3;
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = NumberLabyrinthDiv1().getNumberOfPaths(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), xFinish, yFinish, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int X[]                   = {1, 3, 6};
			int Y[]                   = {1, 3, 6};
			int val[]                 = {2, 2, 2};
			int xFinish               = 5;
			int yFinish               = 5;
			int K                     = 4;
			int expected__            = 210;

			clock_t start__           = clock();
			int received__            = NumberLabyrinthDiv1().getNumberOfPaths(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), xFinish, yFinish, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int X[]                   = {1, 19, 20, 21, 21, 21, 20, 19, 19};
			int Y[]                   = {1, 11, 11, 11, 10, 9, 9, 9, 10};
			int val[]                 = {1, 2, 2, 2, 2, 2, 2, 2, 2};
			int xFinish               = 20;
			int yFinish               = 10;
			int K                     = 4;
			int expected__            = 1778;

			clock_t start__           = clock();
			int received__            = NumberLabyrinthDiv1().getNumberOfPaths(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), xFinish, yFinish, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int X[]                   = {13, 224, 77, 509, 1451, 43, 379, 142, 477};
			int Y[]                   = {1974, 375, 38, 783, 3, 1974, 1790, 1008, 2710};
			int val[]                 = {30, 1845, 360, 11, 837, 84, 210, 4, 6704};
			int xFinish               = 509;
			int yFinish               = 2011;
			int K                     = 10;
			int expected__            = 196052726;

			clock_t start__           = clock();
			int received__            = NumberLabyrinthDiv1().getNumberOfPaths(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), xFinish, yFinish, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int X[]                   = ;
			int Y[]                   = ;
			int val[]                 = ;
			int xFinish               = ;
			int yFinish               = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NumberLabyrinthDiv1().getNumberOfPaths(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), xFinish, yFinish, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int X[]                   = ;
			int Y[]                   = ;
			int val[]                 = ;
			int xFinish               = ;
			int yFinish               = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NumberLabyrinthDiv1().getNumberOfPaths(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), xFinish, yFinish, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int X[]                   = ;
			int Y[]                   = ;
			int val[]                 = ;
			int xFinish               = ;
			int yFinish               = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NumberLabyrinthDiv1().getNumberOfPaths(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), xFinish, yFinish, K);
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
